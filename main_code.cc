// simple example of a clang plugin tool
// which issues warning diagnostics on
// finding pass by value parameters in function arguments
// which are unmodified within function body

#include <llvm-11/llvm/Support/CommandLine.h>
#include <llvm-11/llvm/Support/Debug.h>
#include <unordered_set>
#include <vector>
#include <iostream>
#include <algorithm>

#include "clang/AST/Expr.h"
#include "clang/Frontend/FrontendPluginRegistry.h"
#include "clang/AST/AST.h"
#include "clang/AST/ASTConsumer.h"
#include "clang/AST/RecursiveASTVisitor.h"
#include "clang/Basic/FileManager.h"
#include "clang/Frontend/CompilerInstance.h"
#include "llvm/Support/raw_ostream.h"
using namespace clang;

class MyVisitor : public RecursiveASTVisitor<MyVisitor> {
private:
	ASTContext *context;
	CompilerInstance& instance;
	DiagnosticsEngine& d;

	unsigned int warningID;
	bool isInHeader(Decl *decl) {
		auto loc = decl->getLocation();
		auto floc = context->getFullLoc(loc);
		if (floc.isInSystemHeader()) return true;
		auto entry = floc.getFileEntry()->getName();
		if (entry.endswith(".h") || entry.endswith(".hpp")) {
			return true;
		}
		return false;
	}

	void printWarning(std::string name, Decl *decl) {
		auto loc = context->getFullLoc(decl->getLocation());
		d.Report(loc, warningID) << name;
	}
	void printWarning(std::string name, const Stmt *stmt) {
		auto loc = context->getFullLoc(stmt->getBeginLoc());
		d.Report(loc, warningID) << name;
	}
	void processStatement(const clang::Stmt *statement) {
		std::string type = statement->getStmtClassName();
		if (type == "ReturnStmt") {
			llvm::outs() << "return stmt\n";
			d.Report(context->getFullLoc(statement->getBeginLoc()), warningID) << statement->getStmtClassName();
		} else if (type == "WhileStmt") {
			llvm::outs() << "while stmt\n";
			d.Report(context->getFullLoc(statement->getBeginLoc()), warningID) << statement->getStmtClassName();
		} else if (type == "ForStmt") {
			llvm::outs() << "for stmt\n";
			d.Report(context->getFullLoc(statement->getBeginLoc()), warningID) << statement->getStmtClassName();
		} else if (type == "IfStmt") {
			llvm::outs() << "if stmt\n";
			d.Report(context->getFullLoc(statement->getBeginLoc()), warningID) << statement->getStmtClassName();
		} else if (type == "SwitchStmt") {
			llvm::outs() << "switch stmt\n";
			d.Report(context->getFullLoc(statement->getBeginLoc()), warningID) << statement->getStmtClassName();
		} else if (type == "CompoundStmt") {
			//llvm::outs() << "compound stmt\n";
			d.Report(context->getFullLoc(statement->getBeginLoc()), warningID) << statement->getStmtClassName();
		} else {
			//llvm::outs() << "some other stmt\n";
			d.Report(context->getFullLoc(statement->getBeginLoc()), warningID) << statement->getStmtClassName();
		}
	}
	std::vector<std::string> processFnBody(FunctionDecl *func, bool printDebugs=false) {
		std::vector<std::string> result;
		for(auto stmt : func->getBody()->children()) {
			//processStatement(stmt);

			std::string type = stmt->getStmtClassName();
			if(printDebugs){llvm::outs() << "stmt child: " << stmt->getStmtClassName() << "\n";}
			if(type=="BinaryOperator" || type=="CXXOperatorCallExpr") {
				if(printDebugs)
					printWarning("Possible assignment found", stmt);
				//stmt->dumpColor();
				for(auto x : stmt->children()) {
					if(printDebugs){llvm::outs() << "-- stmt subchild: " << x->getStmtClassName() << "\n";}
					std::string temp_type = x->getStmtClassName();
					if(temp_type=="DeclRefExpr") {
						// DeclRefExpr for normal & MemberExpr for custom classes
						if(printDebugs){llvm::outs() << "-- Assignment LHS found: ";}
						//x->dumpColor();
						DeclRefExpr *DRE = dyn_cast<DeclRefExpr>(x);
						if(printDebugs){llvm::outs() << DRE->getDecl()->getDeclName() << "\n";}
						result.push_back(std::string(DRE->getDecl()->getDeclName().getAsString()));
					} else if(temp_type=="MemberExpr") {
						// DeclRefExpr for normal data types & MemberExpr for custom classes
						if(printDebugs){llvm::outs() << "-- Assignment LHS found: ";}
						//x->dumpColor();
						MemberExpr *ME = dyn_cast<MemberExpr>(x);
						if(printDebugs) {llvm::outs() << ME->getMemberDecl()->getDeclName() << "\n";}
						result.push_back(std::string(ME->getMemberDecl()->getDeclName().getAsString()));
					}
				}
			}
		}
		return result;
	}

public:
	explicit MyVisitor(ASTContext *context, CompilerInstance& instance):
	context(context), instance(instance), d(instance.getDiagnostics()) {
		warningID = d.getCustomDiagID(DiagnosticsEngine::Warning, "Debug: '%0'");
	}

	// write required code here
	virtual bool VisitFunctionDecl(FunctionDecl *func) {
		//func->getBody()->getStmtClass(); // this returns only the first stmt seen
		if(isInHeader(func))
			return true;

		// process function body and find out assignment operations & get LHS of those (TODO: test that it works just for 
		//			assignment operations & not any other kind of operations - currently using BinaryOperations && DeclRefExpr)
		std::vector<std::string> assignmentVars = processFnBody(func, false);

		for(int i=0; i<func->getNumParams(); i++) {
			std::string arg_name = func->parameters()[i]->getQualifiedNameAsString();

			auto x = func->parameters()[i];
			auto y = func->getParamDecl(i);

			// if the argument is NOT a POINTER_TYPE
			if(!y->getType()->isPointerType()) {
				//printWarning("pass by value found: "+arg_name, func);
				//llvm::outs() << "Pass by Value detected: " << y->getName() << "\n";

				// if found in any kind of assignment operation, show warning
				if(std::find(assignmentVars.begin(), assignmentVars.end(), arg_name) != assignmentVars.end())
					printWarning("pass by value argument - "+arg_name+" - possibly modified!!", func);
			}
		}
		return true;
	}
	
	virtual bool VisitStmt(const Stmt *stmt)
	{
		//processStatement(stmt);
		return true;
	}
};

class MyConsumer : public ASTConsumer {
	CompilerInstance& instance;
	MyVisitor visitor;

public:
	MyConsumer(CompilerInstance& instance): instance(instance), visitor(&instance.getASTContext(), instance) {}
	virtual void HandleTranslationUnit(ASTContext &context) override {
		visitor.TraverseDecl(context.getTranslationUnitDecl());
	}
};

class MyAction : public PluginASTAction {
protected:
	virtual std::unique_ptr<ASTConsumer> CreateASTConsumer(CompilerInstance& instance, llvm::StringRef) override {
		return std::make_unique<MyConsumer>(instance);
	}

	virtual bool ParseArgs(const CompilerInstance&, const std::vector<std::string>&) override {
		return true;
	}

	virtual PluginASTAction::ActionType getActionType() override {
  		return PluginASTAction::AddAfterMainAction;
	}
};

static FrontendPluginRegistry::Add<MyAction> CS01("CS01", "Warn against unmodified pass by value function arguments");


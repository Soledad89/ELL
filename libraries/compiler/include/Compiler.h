////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Project:  Embedded Machine Learning Library (EMLL)
//  File:     Compiler.h (compiler)
//  Authors:  Umesh Madan
//
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "ModelEx.h"
#include "Types.h"
#include "SymbolTable.h"
#include "DataFlow.h"

#include <functional>

namespace emll
{
	namespace compiler
	{
		/// <summary>The EMLL compiler</summary>
		class Compiler
		{
		public:

		public:
			Compiler();
			virtual ~Compiler() = default;

			void CompileGraph(DataFlowGraph& graph);

			virtual void Compile(LiteralNode& node) = 0;
			virtual void Compile(BinaryNode& node) = 0;
			virtual void Compile(InputNode& node) = 0;

			EmittedVar AllocLiteral();
			EmittedVar AllocLocal();
			void FreeLocal(EmittedVar var);
			EmittedVar AllocGlobal();
			void FreeGlobal(EmittedVar var);

			virtual void AllocVar(Variable& var);
			virtual void FreeVar(Variable& var);

			void BeginFunctionPredict();
			virtual void BeginFunction(const std::string& functionName, NamedValueTypeList& args) = 0;
			virtual void EndFunction() = 0;

		protected:
			
		private:
			void Reset();

		private:
			EmittedVarAllocator _literalVars;
			EmittedVarAllocator _localVars;
			EmittedVarAllocator _globalVars;
		};
	}
}

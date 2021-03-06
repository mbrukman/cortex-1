//////////////////////////////////////////////////////////////////////////
//
//  Copyright (c) 2007-2010, Image Engine Design Inc. All rights reserved.
//
//  Redistribution and use in source and binary forms, with or without
//  modification, are permitted provided that the following conditions are
//  met:
//
//     * Redistributions of source code must retain the above copyright
//       notice, this list of conditions and the following disclaimer.
//
//     * Redistributions in binary form must reproduce the above copyright
//       notice, this list of conditions and the following disclaimer in the
//       documentation and/or other materials provided with the distribution.
//
//     * Neither the name of Image Engine Design nor the names of any
//       other contributors to this software may be used to endorse or
//       promote products derived from this software without specific prior
//       written permission.
//
//  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
//  IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
//  THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
//  PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
//  CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
//  EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
//  PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
//  PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
//  LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
//  NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
//  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
//////////////////////////////////////////////////////////////////////////

#ifndef IECORESCENE_TYPEDPRIMITIVEOP_H
#define IECORESCENE_TYPEDPRIMITIVEOP_H

#include "IECoreScene/CurvesPrimitive.h"
#include "IECoreScene/MeshPrimitive.h"
#include "IECoreScene/PrimitiveOp.h"

namespace IECoreScene
{

/// The TypedPrimitiveOp template defines a base class for Ops which modify primitives of a specific type.
template<typename T>
class IECORE_EXPORT TypedPrimitiveOp : public IECore::ModifyOp
{
	public :

		typedef T PrimitiveType;

		TypedPrimitiveOp( const std::string &description );
		~TypedPrimitiveOp() override;

		IECORE_RUNTIMETYPED_DECLARETEMPLATE( TypedPrimitiveOp<T>, IECore::ModifyOp );

	protected :

		/// Must be implemented by all subclasses.
		virtual void modifyTypedPrimitive( T *typedPrimitive, const IECore::CompoundObject *operands ) = 0;

	private :

		/// Implemented to call modifyTypedPrimitive
		void modify( IECore::Object *primitive, const IECore::CompoundObject *operands ) override;

		IE_CORE_DECLARERUNTIMETYPEDDESCRIPTION( TypedPrimitiveOp<T> );

};

#define IE_CORE_DEFINETYPEDPRIMITIVEOP( TNAME ) \
	typedef TypedPrimitiveOp<TNAME> (TNAME ## Op); \
	IE_CORE_DECLAREPTR( TNAME ## Op );

IE_CORE_DEFINETYPEDPRIMITIVEOP( MeshPrimitive )
IE_CORE_DEFINETYPEDPRIMITIVEOP( CurvesPrimitive )

} // namespace IECoreScene

#endif // IECORESCENE_TYPEDPRIMITIVEOP_H

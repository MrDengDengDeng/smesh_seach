//  SMESH  SMESH_MeshVSLink : Connection of SMESH with MeshVS from OCC 
//
//  Copyright (C) 2003  OPEN CASCADE, EADS/CCR, LIP6, CEA/DEN,
//  CEDRAT, EDF R&D, LEG, PRINCIPIA R&D, BUREAU VERITAS
//
//  This library is free software; you can redistribute it and/or
//  modify it under the terms of the GNU Lesser General Public
//  License as published by the Free Software Foundation; either
//  version 2.1 of the License.
//
//  This library is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//  Lesser General Public License for more details.
//
//  You should have received a copy of the GNU Lesser General Public
//  License along with this library; if not, write to the Free Software
//  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA
//
// See http://www.salome-platform.org/ or email : webmaster.salome@opencascade.com
//
// File      : SMESH_MeshVSLink.cxx
// Created   : Mon Dec 1 09:00:00 2008
// Author    : Sioutis Fotios
// Module    : SMESH

#ifndef _SMESH_MeshVSLink_HeaderFile
#define _SMESH_MeshVSLink_HeaderFile

#if OCC_VERSION_HEX < 0x070000
#include <Handle_SMESH_MeshVSLink.hxx>
#endif

#include <Standard.hxx>
#include <TColStd_PackedMapOfInteger.hxx>
#include <TColStd_HArray2OfInteger.hxx>
#include <TColStd_HArray2OfReal.hxx>
#include <MeshVS_DataSource3D.hxx>
#include <Standard_Boolean.hxx>
#include <Standard_Integer.hxx>
#include <MeshVS_EntityType.hxx>
#include <Standard_Address.hxx>
#include <TColStd_HArray1OfInteger.hxx>
#include <Standard_Real.hxx>
#include <Standard_Version.hxx>

#include <SMESH_Mesh.hxx>
#include <SMESH_subMesh.hxx>
#include <SMESH_Group.hxx>

#if OCC_VERSION_HEX >= 0x070000
DEFINE_STANDARD_HANDLE(SMESH_MeshVSLink, MeshVS_DataSource3D)
#endif
class SMESH_MeshVSLink : public MeshVS_DataSource3D {

  public:
	// Methods PUBLIC
	//

	//! Constructor <br>
	SMESH_EXPORT SMESH_MeshVSLink(const SMESH_Mesh *aMesh);

	SMESH_EXPORT SMESH_MeshVSLink(const SMESH_subMesh *aSubMesh);

	SMESH_EXPORT SMESH_MeshVSLink(const SMESH_Mesh *aMesh, const SMESH_Group *aGroup);

	//Not implemented yet
	/*

	Standard_EXPORT   Standard_Boolean GetNodeNormal(const Standard_Integer ranknode,const Standard_Integer ElementId,Standard_Real& nx,Standard_Real& ny,Standard_Real& nz) const;
	Standard_EXPORT   Standard_Boolean GetNormalsByElement(const Standard_Integer Id,const Standard_Boolean IsNodal,const Standard_Integer MaxNodes,Handle(TColStd_HArray1OfReal)& Normals) const;
	Standard_EXPORT   void GetAllGroups(TColStd_PackedMapOfInteger& Ids) const;
	Standard_EXPORT   Standard_Boolean GetGroup(const Standard_Integer Id,MeshVS_EntityType& Type,TColStd_PackedMapOfInteger& Ids) const;
	Standard_EXPORT   Standard_Address GetGroupAddr(const Standard_Integer ID) const;
	Standard_EXPORT   Standard_Boolean IsAdvancedSelectionEnabled() const;
	Standard_EXPORT   Bnd_Box GetBoundingBox() const;
	Standard_EXPORT   Standard_Boolean GetDetectedEntities(const Handle(MeshVS_Mesh)& Prs,const Standard_Real X,const Standard_Real Y,const Standard_Real aTol,Handle(TColStd_HPackedMapOfInteger)& Nodes,Handle(TColStd_HPackedMapOfInteger)& Elements) ;
	Standard_EXPORT   Standard_Boolean GetDetectedEntities(const Handle(MeshVS_Mesh)& Prs,const Standard_Real XMin,const Standard_Real YMin,const Standard_Real XMax,const Standard_Real YMax,const Standard_Real aTol,Handle(TColStd_HPackedMapOfInteger)& Nodes,Handle(TColStd_HPackedMapOfInteger)& Elements) ;
	Standard_EXPORT   Standard_Boolean GetDetectedEntities(const Handle(MeshVS_Mesh)& Prs,const TColgp_Array1OfPnt2d& Polyline,const Bnd_Box2d& aBox,const Standard_Real aTol,Handle(TColStd_HPackedMapOfInteger)& Nodes,Handle(TColStd_HPackedMapOfInteger)& Elements) ;
	Standard_EXPORT   Standard_Boolean GetDetectedEntities(const Handle(MeshVS_Mesh)& Prs,Handle(TColStd_HPackedMapOfInteger)& Nodes,Handle(TColStd_HPackedMapOfInteger)& Elements) ;
	*/

	//! Returns geometry information about node ( if IsElement is False ) or element ( IsElement is True ) <br>
	//! by co-ordinates. For element this method must return all its nodes co-ordinates in the strict order: X, Y, Z and <br>
	//! with nodes order is the same as in wire bounding the face or link. NbNodes is number of nodes of element. <br>
	//! It is recommended to return 1 for node. Type is an element type. <br>
	SMESH_EXPORT   Standard_Boolean GetGeom(const Standard_Integer ID,const Standard_Boolean IsElement,TColStd_Array1OfReal& Coords,Standard_Integer& NbNodes,MeshVS_EntityType& Type) const override;

	SMESH_EXPORT   Standard_Boolean Get3DGeom(const Standard_Integer ID,Standard_Integer& NbNodes,Handle(MeshVS_HArray1OfSequenceOfInteger)& Data) const override;

	//! This method is similar to GetGeom, but returns only element or node type. This method is provided for <br>
	//! a fine performance. <br>
	SMESH_EXPORT   Standard_Boolean GetGeomType(const Standard_Integer ID,const Standard_Boolean IsElement,MeshVS_EntityType& Type) const override;

	//! This method returns by number an address of any entity which represents element or node data structure. <br>
	SMESH_EXPORT   Standard_Address GetAddr(const Standard_Integer ID,const Standard_Boolean IsElement) const override;

	//! This method returns information about what node this element consist of. <br>
	SMESH_EXPORT /*virtual*/  Standard_Boolean GetNodesByElement(const Standard_Integer ID,TColStd_Array1OfInteger& NodeIDs,Standard_Integer& NbNodes) const override;

	//! This method returns map of all nodes the object consist of. <br>
	SMESH_EXPORT  const TColStd_PackedMapOfInteger& GetAllNodes() const override;

	//! This method returns map of all elements the object consist of. <br>
	SMESH_EXPORT  const TColStd_PackedMapOfInteger& GetAllElements() const override;

	//! This method calculates normal of face, which is using for correct reflection presentation. <br>
	//! There is default method, for advance reflection this method can be redefined. <br>
	SMESH_EXPORT Standard_Boolean GetNormal(const Standard_Integer Id,const Standard_Integer Max,Standard_Real& nx,Standard_Real& ny,Standard_Real& nz) const override;

	//! This method returns map of all groups the object contains. <br>
	SMESH_EXPORT void GetAllGroups(TColStd_PackedMapOfInteger& Ids) const override;

	// Find element from mesh element ID
	SMESH_EXPORT const SMDS_MeshElement* FindElement(const int ID) const;

	// Find node from mesh node ID
	SMESH_EXPORT const SMDS_MeshNode* FindNode(const int ID) const;

	// Type management
	//
#if OCC_VERSION_HEX >= 0x070000
    DEFINE_STANDARD_RTTIEXT(SMESH_MeshVSLink,MeshVS_DataSource3D)
#else
    Standard_EXPORT const Handle(Standard_Type)& DynamicType() const;
#endif

  protected:
	// Methods PROTECTED
	//

	// Fields PROTECTED
	//

  private:
	// Methods PRIVATE
	//

	// Fields PRIVATE
	//
	SMESH_Mesh *myMesh;
	TColStd_PackedMapOfInteger myNodes;
	TColStd_PackedMapOfInteger myElements;
	TColStd_PackedMapOfInteger myGroups;
	SMESH_subMesh *mySubMesh;
	SMESH_Group *myGroup;
};
#include <SMESH_MeshVSLink.ixx>
// other Inline functions and methods (like "C++: function call" methods)
//
#endif

/*
 * FILE: A3DAutoFish.h
 *
 * DESCRIPTION: One kind of autonomous agent in Angelica Engine, to simulate fish behaviour
 *
 * CREATED BY: Changzhi Li, 2004/11/22
 *
 * HISTORY:
 *
 * Copyright (c) 2001~2008 Archosaur Studio, All Rights Reserved.
 */

#ifndef _A3DAUTOFISH_H_
#define _A3DAUTOFISH_H_

#include "A3DAutonomousAgent.h"

class A3DAutoFish : public A3DAutonomousAgent
{
public:
	A3DAutoFish () : A3DAutonomousAgent() { Reset(); }

	virtual void ApplySteeringForce (float fElapsedTime);		// time in sec

	virtual A3DVECTOR3	SteerForWander (float fElapsedTime);	// time in sec
	virtual A3DVECTOR3	SteerForSeek (const A3DVECTOR3& target);
	virtual A3DVECTOR3	SteerForFlee (const A3DVECTOR3& target);

	virtual bool		IsInBoidNeighborhood (const A3DAutonomousAgent* other, float minDistance, float maxDistance, float cosMaxAngle);
	virtual A3DVECTOR3	SteerForSeparation (float maxDistance, float cosMaxAngle, const A3DAutonomousGroup* pGroup);
	virtual A3DVECTOR3	SteerForAlignment (float maxDistance, float cosMaxAngle, const A3DAutonomousGroup* pGroup);
	virtual A3DVECTOR3	SteerForCohesion (float maxDistance, float cosMaxAngle, const A3DAutonomousGroup* pGroup);

	virtual void	RegenerateLocalSpace (A3DVECTOR3 vNewForward, float fBankAngle);	
	virtual void	Update (DWORD dwDeltaTime, ActionList_e action = ACTION_FIRST);			// time in msec
	virtual void	Reset (void);
	
	virtual A3DVECTOR3 RespondToBoundary (const A3DVECTOR3& vCenter, float fBoundaryRadius);
	virtual void	ClampPosition (A3DTerrain2 * pTerrain, A3DTerrainWater * pTerrainWater, DWORD dwDeltaTime);

protected:
	void	ClampAboveTerrain (A3DVECTOR3 vPredicted, A3DTerrain2 * pTerrain);
	void	ClampUnderTerrainWater (A3DVECTOR3 vPredicted, A3DTerrainWater * pTerrainWater);

};

class A3DAutoDoltishFish : public A3DAutonomousAgent
{
public:
	A3DAutoDoltishFish () : A3DAutonomousAgent() { Reset(); }

	virtual void ApplySteeringForce (float fElapsedTime);		// time in sec

	virtual A3DVECTOR3	SteerForWander (float fElapsedTime);	// time in sec
	virtual A3DVECTOR3	SteerForSeek (const A3DVECTOR3& target);
	virtual A3DVECTOR3	SteerForFlee (const A3DVECTOR3& target);

	virtual bool		IsInBoidNeighborhood (const A3DAutonomousAgent* other, float minDistance, float maxDistance, float cosMaxAngle);
	virtual A3DVECTOR3	SteerForSeparation (float maxDistance, float cosMaxAngle, const A3DAutonomousGroup* pGroup);
	virtual A3DVECTOR3	SteerForAlignment (float maxDistance, float cosMaxAngle, const A3DAutonomousGroup* pGroup);
	virtual A3DVECTOR3	SteerForCohesion (float maxDistance, float cosMaxAngle, const A3DAutonomousGroup* pGroup);

	virtual void	RegenerateLocalSpace (A3DVECTOR3 vNewForward, float fBankAngle);	
	virtual void	Update (DWORD dwDeltaTime, ActionList_e action = ACTION_FIRST);			// time in msec
	virtual void	Reset (void);
	
	virtual A3DVECTOR3 RespondToBoundary (const A3DVECTOR3& vCenter, float fBoundaryRadius);
	virtual void	ClampPosition (A3DTerrain2 * pTerrain, A3DTerrainWater * pTerrainWater, DWORD dwDeltaTime);

protected:
	void	ClampAboveTerrain (A3DVECTOR3 vPredicted, A3DTerrain2 * pTerrain);
	void	ClampUnderTerrainWater (A3DVECTOR3 vPredicted, A3DTerrainWater * pTerrainWater);

};

class A3DAutoBriskFish : public A3DAutonomousAgent
{
public:
	A3DAutoBriskFish () : A3DAutonomousAgent() { Reset(); }

	virtual void ApplySteeringForce (float fElapsedTime);		// time in sec

	virtual A3DVECTOR3	SteerForWander (float fElapsedTime);	// time in sec
	virtual A3DVECTOR3	SteerForSeek (const A3DVECTOR3& target);
	virtual A3DVECTOR3	SteerForFlee (const A3DVECTOR3& target);

	virtual bool		IsInBoidNeighborhood (const A3DAutonomousAgent* other, float minDistance, float maxDistance, float cosMaxAngle);
	virtual A3DVECTOR3	SteerForSeparation (float maxDistance, float cosMaxAngle, const A3DAutonomousGroup* pGroup);
	virtual A3DVECTOR3	SteerForAlignment (float maxDistance, float cosMaxAngle, const A3DAutonomousGroup* pGroup);
	virtual A3DVECTOR3	SteerForCohesion (float maxDistance, float cosMaxAngle, const A3DAutonomousGroup* pGroup);

	virtual void	RegenerateLocalSpace (A3DVECTOR3 vNewForward, float fBankAngle);	
	virtual void	Update (DWORD dwDeltaTime, ActionList_e action = ACTION_FIRST);			// time in msec
	virtual void	Reset (void);
	
	virtual A3DVECTOR3 RespondToBoundary (const A3DVECTOR3& vCenter, float fBoundaryRadius);
	virtual void	ClampPosition (A3DTerrain2 * pTerrain, A3DTerrainWater * pTerrainWater, DWORD dwDeltaTime);

protected:
	void	ClampAboveTerrain (A3DVECTOR3 vPredicted, A3DTerrain2 * pTerrain);
	void	ClampUnderTerrainWater (A3DVECTOR3 vPredicted, A3DTerrainWater * pTerrainWater);

};

#endif
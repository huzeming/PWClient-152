/*
 * FILE: A3DPI.cpp
 *
 * DESCRIPTION: 
 *
 * CREATED BY: duyuxin, 2005/12/19
 *
 * HISTORY:
 *
 * Copyright (c) 2001 Archosaur Studio, All Rights Reserved.	
 */

#include "A3DMacros.h"

///////////////////////////////////////////////////////////////////////////
//
//	Define and Macro
//
///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////
//
//	Reference to External variables and functions
//
///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////
//
//	Local Types and Variables and Global variables
//
///////////////////////////////////////////////////////////////////////////

static const float l_fInvInter = 256.0f / 360.0f;

static const float l_aCos[256] = 
{
	1.000000f, 0.999699f, 0.998795f, 0.997290f,
	0.995185f, 0.992480f, 0.989177f, 0.985278f,
	0.980785f, 0.975702f, 0.970031f, 0.963776f,
	0.956940f, 0.949528f, 0.941544f, 0.932993f,
	0.923880f, 0.914210f, 0.903989f, 0.893224f,
	0.881921f, 0.870087f, 0.857729f, 0.844854f,
	0.831470f, 0.817585f, 0.803208f, 0.788346f,
	0.773010f, 0.757209f, 0.740951f, 0.724247f,
	0.707107f, 0.689541f, 0.671559f, 0.653173f,
	0.634393f, 0.615232f, 0.595699f, 0.575808f,
	0.555570f, 0.534998f, 0.514103f, 0.492898f,
	0.471397f, 0.449611f, 0.427555f, 0.405241f,
	0.382683f, 0.359895f, 0.336890f, 0.313682f,
	0.290285f, 0.266713f, 0.242980f, 0.219101f,
	0.195090f, 0.170962f, 0.146730f, 0.122411f,
	0.098017f, 0.073564f, 0.049068f, 0.024541f,
	-0.000000f, -0.024541f, -0.049068f, -0.073565f,
	-0.098017f, -0.122411f, -0.146731f, -0.170962f,
	-0.195090f, -0.219101f, -0.242980f, -0.266713f,
	-0.290285f, -0.313682f, -0.336890f, -0.359895f,
	-0.382684f, -0.405241f, -0.427555f, -0.449611f,
	-0.471397f, -0.492898f, -0.514103f, -0.534998f,
	-0.555570f, -0.575808f, -0.595699f, -0.615232f,
	-0.634393f, -0.653173f, -0.671559f, -0.689541f,
	-0.707107f, -0.724247f, -0.740951f, -0.757209f,
	-0.773010f, -0.788346f, -0.803208f, -0.817585f,
	-0.831470f, -0.844854f, -0.857729f, -0.870087f,
	-0.881921f, -0.893224f, -0.903989f, -0.914210f,
	-0.923880f, -0.932993f, -0.941544f, -0.949528f,
	-0.956940f, -0.963776f, -0.970031f, -0.975702f,
	-0.980785f, -0.985278f, -0.989177f, -0.992480f,
	-0.995185f, -0.997290f, -0.998795f, -0.999699f,
	-1.000000f, -0.999699f, -0.998795f, -0.997290f,
	-0.995185f, -0.992480f, -0.989177f, -0.985278f,
	-0.980785f, -0.975702f, -0.970031f, -0.963776f,
	-0.956940f, -0.949528f, -0.941544f, -0.932993f,
	-0.923880f, -0.914210f, -0.903989f, -0.893224f,
	-0.881921f, -0.870087f, -0.857729f, -0.844854f,
	-0.831470f, -0.817585f, -0.803208f, -0.788346f,
	-0.773010f, -0.757209f, -0.740951f, -0.724247f,
	-0.707107f, -0.689541f, -0.671559f, -0.653173f,
	-0.634393f, -0.615232f, -0.595699f, -0.575808f,
	-0.555570f, -0.534997f, -0.514103f, -0.492898f,
	-0.471397f, -0.449611f, -0.427555f, -0.405241f,
	-0.382683f, -0.359895f, -0.336890f, -0.313682f,
	-0.290285f, -0.266713f, -0.242980f, -0.219101f,
	-0.195090f, -0.170962f, -0.146730f, -0.122411f,
	-0.098017f, -0.073564f, -0.049067f, -0.024541f,
	0.000000f, 0.024541f, 0.049068f, 0.073565f,
	0.098017f, 0.122411f, 0.146730f, 0.170962f,
	0.195090f, 0.219101f, 0.242980f, 0.266713f,
	0.290285f, 0.313682f, 0.336890f, 0.359895f,
	0.382684f, 0.405242f, 0.427555f, 0.449612f,
	0.471397f, 0.492898f, 0.514103f, 0.534998f,
	0.555570f, 0.575808f, 0.595699f, 0.615232f,
	0.634393f, 0.653173f, 0.671559f, 0.689541f,
	0.707107f, 0.724247f, 0.740951f, 0.757209f,
	0.773011f, 0.788347f, 0.803208f, 0.817585f,
	0.831470f, 0.844854f, 0.857729f, 0.870087f,
	0.881921f, 0.893224f, 0.903989f, 0.914210f,
	0.923880f, 0.932993f, 0.941544f, 0.949528f,
	0.956940f, 0.963776f, 0.970031f, 0.975702f,
	0.980785f, 0.985278f, 0.989177f, 0.992480f,
	0.995185f, 0.997290f, 0.998795f, 0.999699f,
};

static const float l_aSin[256] = 
{
	0.000000f, 0.024541f, 0.049068f, 0.073565f,
	0.098017f, 0.122411f, 0.146730f, 0.170962f,
	0.195090f, 0.219101f, 0.242980f, 0.266713f,
	0.290285f, 0.313682f, 0.336890f, 0.359895f,
	0.382683f, 0.405241f, 0.427555f, 0.449611f,
	0.471397f, 0.492898f, 0.514103f, 0.534998f,
	0.555570f, 0.575808f, 0.595699f, 0.615232f,
	0.634393f, 0.653173f, 0.671559f, 0.689541f,
	0.707107f, 0.724247f, 0.740951f, 0.757209f,
	0.773010f, 0.788346f, 0.803208f, 0.817585f,
	0.831470f, 0.844854f, 0.857729f, 0.870087f,
	0.881921f, 0.893224f, 0.903989f, 0.914210f,
	0.923880f, 0.932993f, 0.941544f, 0.949528f,
	0.956940f, 0.963776f, 0.970031f, 0.975702f,
	0.980785f, 0.985278f, 0.989177f, 0.992480f,
	0.995185f, 0.997290f, 0.998795f, 0.999699f,
	1.000000f, 0.999699f, 0.998795f, 0.997290f,
	0.995185f, 0.992480f, 0.989176f, 0.985278f,
	0.980785f, 0.975702f, 0.970031f, 0.963776f,
	0.956940f, 0.949528f, 0.941544f, 0.932993f,
	0.923880f, 0.914210f, 0.903989f, 0.893224f,
	0.881921f, 0.870087f, 0.857729f, 0.844854f,
	0.831470f, 0.817585f, 0.803207f, 0.788346f,
	0.773010f, 0.757209f, 0.740951f, 0.724247f,
	0.707107f, 0.689540f, 0.671559f, 0.653173f,
	0.634393f, 0.615231f, 0.595699f, 0.575808f,
	0.555570f, 0.534997f, 0.514103f, 0.492898f,
	0.471397f, 0.449611f, 0.427555f, 0.405241f,
	0.382683f, 0.359895f, 0.336890f, 0.313682f,
	0.290285f, 0.266713f, 0.242980f, 0.219101f,
	0.195090f, 0.170962f, 0.146730f, 0.122411f,
	0.098017f, 0.073564f, 0.049067f, 0.024541f,
	-0.000000f, -0.024541f, -0.049068f, -0.073565f,
	-0.098017f, -0.122411f, -0.146731f, -0.170962f,
	-0.195090f, -0.219101f, -0.242980f, -0.266713f,
	-0.290285f, -0.313682f, -0.336890f, -0.359895f,
	-0.382683f, -0.405241f, -0.427555f, -0.449612f,
	-0.471397f, -0.492898f, -0.514103f, -0.534998f,
	-0.555570f, -0.575808f, -0.595699f, -0.615232f,
	-0.634393f, -0.653173f, -0.671559f, -0.689541f,
	-0.707107f, -0.724247f, -0.740951f, -0.757209f,
	-0.773010f, -0.788346f, -0.803208f, -0.817585f,
	-0.831470f, -0.844854f, -0.857729f, -0.870087f,
	-0.881921f, -0.893224f, -0.903989f, -0.914210f,
	-0.923880f, -0.932993f, -0.941544f, -0.949528f,
	-0.956940f, -0.963776f, -0.970031f, -0.975702f,
	-0.980785f, -0.985278f, -0.989177f, -0.992480f,
	-0.995185f, -0.997290f, -0.998795f, -0.999699f,
	-1.000000f, -0.999699f, -0.998795f, -0.997290f,
	-0.995185f, -0.992479f, -0.989177f, -0.985278f,
	-0.980785f, -0.975702f, -0.970031f, -0.963776f,
	-0.956940f, -0.949528f, -0.941544f, -0.932993f,
	-0.923879f, -0.914210f, -0.903989f, -0.893224f,
	-0.881921f, -0.870087f, -0.857729f, -0.844853f,
	-0.831469f, -0.817585f, -0.803208f, -0.788346f,
	-0.773010f, -0.757209f, -0.740951f, -0.724247f,
	-0.707107f, -0.689541f, -0.671559f, -0.653173f,
	-0.634393f, -0.615231f, -0.595699f, -0.575808f,
	-0.555570f, -0.534998f, -0.514103f, -0.492898f,
	-0.471397f, -0.449611f, -0.427555f, -0.405241f,
	-0.382683f, -0.359895f, -0.336890f, -0.313682f,
	-0.290284f, -0.266712f, -0.242980f, -0.219101f,
	-0.195090f, -0.170962f, -0.146730f, -0.122410f,
	-0.098017f, -0.073565f, -0.049068f, -0.024541f,
};

///////////////////////////////////////////////////////////////////////////
//
//	Local functions
//
///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////
//
//	Implement
//
///////////////////////////////////////////////////////////////////////////

//	Compress horizontal direction to a byte
BYTE a3d_CompressDirH(float x, float z)
{
	if (fabs(x) < 0.00001)
	{
		if (z > 0.0f)
			return 64;
		else
			return 192;
	}
	else
	{
		float fDeg = RAD2DEG((float)atan2(z, x));
		return (BYTE)(fDeg * l_fInvInter);
	}
}

//	Decompress horizontal direction
A3DVECTOR3 a3d_DecompressDirH(BYTE byDir)
{
	return A3DVECTOR3(l_aCos[byDir], 0.0f, l_aSin[byDir]);
}

//	Compress direction to two bytes
void a3d_CompressDir(const A3DVECTOR3& v, BYTE& b1, BYTE& b2)
{
	if (1.0 - fabs(v.y) < 0.0001)
	{
		b1 = 0;
		b2 = v.y < 0.0f ? 128 : 0;
		return;
	}

	A3DVECTOR3 vh(v.x, 0.0f, v.z);
	vh.Normalize();

	if (fabs(vh.x) < 0.00001)
	{
		if (vh.z > 0.0f)
			b1 = 64;
		else
			b1 = 192;
	}
	else
	{
		float fDeg = RAD2DEG((float)atan2(vh.z, vh.x));
		b1 = (BYTE)(fDeg * l_fInvInter);
	}

	float fDeg = RAD2DEG((float)acos(v.y));
	b2 = (BYTE)(fDeg * l_fInvInter);
}

//	Decompress direction from two bytes
A3DVECTOR3 a3d_DecompressDir(BYTE b1, BYTE b2)
{
	A3DVECTOR3 v;
	float p = l_aSin[b2];
	v.x = p * l_aCos[b1];
	v.z = p * l_aSin[b1];
	v.y = l_aCos[b2];

	return v;
}

#pragma once
#include "ZCVector.h"


//顶点信息 包括坐标，颜色，纹理坐标，法线等等
class VertexIn
{
public:
	//顶点位置
	ZCVector pos;
	//顶点颜色
	ZCFLOAT3 color;
	//纹理坐标
	ZCFLOAT2 tex;
	//法线
	ZCVector normal;

	VertexIn() = default;
	VertexIn(ZCVector pos, ZCFLOAT3 color, ZCFLOAT2 tex, ZCVector normal)
	{
		this->pos = pos;
		this->color = color;
		this->tex = tex;
		this->normal = normal;
	}

	VertexIn(const VertexIn& rhs):pos(rhs.pos),color(rhs.color),tex(rhs.tex),normal(rhs.normal){}
};

//经过顶点着色器输出的结构
class VertexOut
{
public:
	//世界变换后的坐标
	ZCVector posTrans;
	//投影变换后的坐标
	ZCVector posH;
	//纹理坐标
	ZCFLOAT2 tex;
	//法线
	ZCVector normal;
	//颜色
	ZCFLOAT3 color;
	//1/z用于深度测试
	float oneDivZ;

	VertexOut() = default;
	VertexOut(ZCVector posT,ZCVector posH,ZCFLOAT2 tex, ZCVector normal,ZCFLOAT3 color,float oneDivZ)
	{
		this->posTrans = posT;
		this->posH = posH;
		this->tex = tex;
		this->normal = normal;
		this->color = color;
		this->oneDivZ = oneDivZ;
	}
	

	VertexOut(const VertexOut& rhs) :posTrans(rhs.posTrans), posH(rhs.posH), tex(rhs.tex), normal(rhs.normal),
	color(rhs.color),oneDivZ(rhs.oneDivZ){}

	VertexOut& operator= (const VertexOut& rhs)
	{
		if (this == &rhs)
			return *this;
		this->normal = rhs.normal;
		this->posH = rhs.posH;
		this->posTrans = rhs.posTrans;
		this->tex = rhs.tex;
		this->color = rhs.color;
		this->oneDivZ = rhs.oneDivZ;
		return *this;
	}
};


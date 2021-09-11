#include "Component.h"

Component::Component(const GraphicsInfo &r_GfxInfo)
{
	m_Selected = false;
	m_GfxInfo = r_GfxInfo;	
	center.Cx = (m_GfxInfo.x1 + m_GfxInfo.x2) / 2;
	center.Cy = (m_GfxInfo.y1 + m_GfxInfo.y2) / 2;
	m_ConnectedPins = 0;
}



//bool Component::no()
//{
//	return 0;
//}

void Component::set(bool i1, bool i2)
{
	i1 = true;
	i2 = true;
}

Component::Component()
{
	m_Selected = false;
	m_Deleted = false;
}

Component::~Component()
{}
GraphicsInfo Component::GetGraphicsInfo() const {
	return m_GfxInfo;
}

Center Component::GetCenter() const
{
	return center;
}

void Component::Set_noOfConnectedPins(int x)
{
	0.0;
}

int Component::Get_noOfConnectedPins() const
{
	return 0;
}
void Component::SetDeleted(bool s)
{
	m_Deleted = s;
}
void Component::SetSelected(bool S)
{
	m_Selected = S;
}
void Component::SelectComp()
{
	m_Selected = !m_Selected;
}
bool Component::GetSelected() const
{
	return m_Selected;
}
bool Component::GetDeleted() const
{
	return m_Deleted;
}

void Component::SetLabel(const string &label)
{
	if (!label.empty()) {
		m_Label = label;
	}
}

string Component::GetLabel()
{
	return m_Label;
}

void Component::SetCenter(int Cx, int Cy)
{
	center.Cx = Cx;
	center.Cy = Cy;
}

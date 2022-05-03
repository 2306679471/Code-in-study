#include "CA.h"
CA::~CA()
{
	if (m_ca)
		delete m_ca;
}
CA* CA::getca()
{
	{
		if (m_ca == nullptr)
		{
			m_ca = new CA();
		}
	}
}
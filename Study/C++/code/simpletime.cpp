#include<stdexcept>
#include"simpletime.h"
using namespace std;
simpleTime::simpleTime(int shi, int fen, int miao)
{
	setTime(shi, fen, miao);
}
void simpleTime::setTime(int shi, int fen, int miao)
{
	if( (shi >= 0 && shi < 24) && (fen >= 0 && fen < 60) && (miao >= 0 && miao < 60))
	{
		h = shi;
		m = fen;
		s = miao;
	}
	else
		throw invalid_argument("输入错误\n");
}
unsigned int simpleTime::getH()const
{
	return h;
}
unsigned int& simpleTime::setH(unsigned int shi)
{
	if (shi >= 0 && shi < 24)
	{
		h = shi;
	}
	else
		throw invalid_argument("时设置有误\n");
	return h;
}
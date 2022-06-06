//2 - 1	 課本習題第十三章的第4題(功能必須涵蓋第2到第3題的描述)，主程式如下
#include<iostream>
#include<cstdlib>
#include<iomanip>
#include<math.h>
using namespace std;

class CVector 
{
   private:
	   float m_fx, m_fy;

   public:
	   CVector(int x , int y ) 
	   {
		   m_fx = x;
		   m_fy = y;
		   Dist();
	   }
	   CVector(int a=0)
	   {
		   m_fx = a;
		   m_fy = a;
		   Dist();
	   }
	  

	   void Show() 
	   {
		   system("cls");
		   cout << (m_fx, m_fy);
	   }

	   float m_fNorm;

	   float Dist() 
	   {
		   m_fNorm = sqrt((m_fx * m_fx) + (m_fy * m_fy));
	   }
	   void ShowNorm() 
	   {
		   cout << m_fNorm;
	   }
	   float Dist(const CVector &v)
	   {
		   float dd;
		   dd=sqrt((m_fx - v.m_fx) * (m_fx - v.m_fx) + (m_fy - v.m_fy) * (m_fy - v.m_fy));
		   return(dd);
	   }

	   float operator*(CVector& v)
	   {
		   return(m_fx * v.m_fx + m_fy * v.m_fy);
	   }
	   float operator-(CVector& v)
	   {
		   return(m_fNorm - v.m_fNorm);
	   }
	   float operator+(CVector& v)
	   {
		   return(m_fNorm + v.m_fNorm);
	   }
	   bool operator>(CVector& v)
	   {
		   if (m_fNorm > v.m_fNorm)
		   {
			   return(true);
		   }
		   else return(false);
	   }
	   bool operator>(int s)
	   {
		   if (m_fNorm > s) { return(true); }
		   else return(false);
	   }

	   int main(void)
	   {
		   CVector v1;  CVector v2(1); 	CVector v3(1, 3); 	CVector v4(v2);
		   bool bRet;
		   v1.ShowNorm(); v2.ShowNorm();
		   v2.Show(); cout << " 到 "; v3.Show();
		   cout << " 的距離為: " << v2.Dist(v3) << endl;
		   cout << "v2 * v3 = " << setw(8) << v2 * v3 << endl;
		   cout << "v2 - v3 = " << setw(8) << v2 - v3 << endl;
		   cout << "v2 + v3 = " << setw(8) << v2 + v3 << endl;
		   bRet = v3 > v2;
		   cout << "v3 > v2 = " << setw(8) << bRet << endl;
		   bRet = v3 > 5;
		   cout << "v3 > 5  = " << setw(8) << bRet << endl;
		   system("pause"); return(0);
	   }


};

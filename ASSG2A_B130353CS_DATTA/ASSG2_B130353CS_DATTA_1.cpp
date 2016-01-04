#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cstring>
#include <climits>
#include <ctime>
#include <cmath>
#include <cstdio>
using namespace std;
int l[1048578],ri[1048578];
void merge(int a[],int p,int q,int r)
{
    int i,j;
    int n1 = q-p+1;
    int n2 = r-q;
    for(i=1;i <= n1 ;i++)
    {
        l[i] = a[p+i-1];
    }
    l[i] = INT_MAX;
    for(j=1;j <= n2 ;j++)
    {
        ri[j] = a[q+j];
    }
    ri[j] = INT_MAX;
    i = 1;
    j = 1;
    int k;
    for ( k = p; k <= r ; k++)
    {
        if(l[i] <= ri[j])
        {
            a[k] = l[i];
            i++;
        }
        else
        {
            a[k] = ri[j];
            j++;
        }
    }

}
void Merge_sort(int a[],int p,int r)
{
    if (p < r)
    {
        int q = floor((p+r)/2);
        Merge_sort(a,p,q);
        Merge_sort(a,q+1,r);
        merge(a,p,q,r);
    }
}
void way4(fstream &file1,fstream &file2,fstream &file3,fstream &file4,fstream &mer1)
{
   int i,count1 = 0,a,b,c,d,count2 = 0 ,count3 = 0 ,count4 = 0 ,num[5];
    file1 >> num[1];
    file2 >> num[2];
    file3 >> num[3];
    file4 >> num[4];
    a = num[1];
    b = num[2];
    c = num[3];
    d = num[4];
    for(i=0;i<(1024*1024*8*4);i++) 
    {
    Merge_sort(num,1,4);
        if(num[1] == a)
        {
            mer1 << a << endl;
            file1 >> num[1];
            count1++;
        if(count1 == 1024*1024*8)
            num[1] = INT_MAX;
    a = num[1];
        }
        else if(num[1] == b)
        {          
          mer1 << b << endl;
            file2 >> num[1];
            count2++;
        if(count2 == 1024*1024*8)
            num[1] = INT_MAX;
    b = num[1];
        }
        else if(num[1] == c)
        {
            mer1 << c << endl;
            file3 >> num[1];
            count3++;
        if(count3 == 1024*1024*8)
            num[1] = INT_MAX;
    c = num[1];
        }
        else
        {          
          mer1 << d << endl;
            file4 >> num[1];
            count4++;
        if(count4 == 1024*1024*8)
            num[1] = INT_MAX;
    d = num[1];
        }
    }
}

void way8(fstream &file1,fstream &file2,fstream &file3,fstream &file4,fstream &file5,fstream &file6,fstream &file7,fstream &file8,fstream &mer1)
{
   int i,count1 = 0,a,b,c,d,e,f,g,h,count2 = 0 ,count8 = 0 ,count7 = 0 ,count6 = 0 ,count5 = 0 ,count3 = 0 ,count4 = 0 ,num[9];
    file1 >> num[1];
    file2 >> num[2];
    file3 >> num[3];
    file4 >> num[4];
    file5 >> num[5];
    file6 >> num[6];
    file7 >> num[7];
    file8 >> num[8];

    a = num[1];
    b = num[2];
    c = num[3];
    d = num[4];
    e = num[5];
    f = num[6];
    g = num[7];
    h = num[8];

    for(i=0;i<(1024*1024*8);i++) 
    {

    Merge_sort(num,1,8);

        if(num[1] == a)
        {
            mer1 << a << endl;
            file1 >> num[1];
            count1++;
        if(count1 == 1024*1024)
            num[1] = INT_MAX;
        a = num[1];

        }
        else if(num[1] == b)
        {          
          mer1 << b << endl;
            file2 >> num[1];
            count2++;
        if(count2 == 1024*1024)
            num[1] = INT_MAX;
        b = num[1];
        }
        else if(num[1] == c)
        {
            mer1 << c << endl;
            file3 >> num[1];
            count3++;
        if(count3 == 1024*1024)
            num[1] = INT_MAX;
        c = num[1];
        }
        else if(num[1] == d)
        {          
          mer1 << d << endl;
            file4 >> num[1];
            count4++;
        if(count4 == 1024*1024)
            num[1] = INT_MAX;
        d = num[1];
        }
        else if(num[1] == e)
        {          
          mer1 << e << endl;
            file5 >> num[1];
            count5++;
        if(count5 == 1024*1024)
            num[1] = INT_MAX;
        e = num[1];
        }
    else if(num[1] == f)
        {          
          mer1 << f << endl;
            file6 >> num[1];
            count6++;
        if(count6 == 1024*1024)
            num[1] = INT_MAX;
        f = num[1];
        }
        else if(num[1] == g)
        {          
          mer1 << g << endl;
            file7 >> num[1];
            count7++;
        if(count7 == 1024*1024)
            num[1] = INT_MAX;
        g = num[1];
        }
        else 
        {          
          mer1 << h << endl;
            file8 >> num[1];
            count8++;
        if(count8 == 1024*1024)
            num[1] = INT_MAX;
        h = num[1];
        }
    }

}
void way2(fstream &ofile,fstream &nfile,fstream &mer1)
{
     int i,count1 = 0,count2 = 0 ,num1,num2;
    ofile >> num1;
    nfile >> num2;
    for(i=0;i<(1024*1024*64);i++) 
    {
        if(num1 < num2)
        {
            mer1 << num1 << endl;
            ofile >> num1;
            count1++;
        }
        else 
        {          
          mer1 << num2 << endl;
            nfile >> num2;
            count2++;
        }
        if(count1 == 1024*1024*32)
            num1 = INT_MAX;
        if(count2 == 1024*1024*32)
            num2 = INT_MAX;
    }
    ofile.close();
    nfile.close();
    mer1.close();
}
int main()
{

    char n, p  ;
    int s = 1048576*64,size = 1048576*64,number,nsize;
    float average=0;
    char filename[64][10]={"1.txt","2.txt","3.txt","4.txt","5.txt","6.txt","7.txt","8.txt","9.txt","10.txt",
                            "11.txt","12.txt","13.txt","14.txt","15.txt","16.txt","17.txt","18.txt","19.txt","20.txt",
                            "21.txt","22.txt","23.txt","24.txt","25.txt","26.txt","27.txt","28.txt","29.txt","30.txt",
                            "31.txt","32.txt","33.txt","34.txt","35.txt","36.txt","37.txt","38.txt","39.txt","40.txt",
                            "41.txt","42.txt","43.txt","44.txt","45.txt","46.txt","47.txt","48.txt","49.txt","50.txt",
                            "51.txt","52.txt","53.txt","54.txt","55.txt","56.txt","57.txt","58.txt","59.txt","60.txt",
                            "61.txt","62.txt","63.txt","64.txt"};
    char merge4[8][10]={"mer1.txt","mer2.txt","mer3.txt","mer4.txt","mer5.txt","mer6.txt","mer7.txt","mer8.txt"};
    char merge2[2][10] = {"s1.txt","s2.txt"};
    int w[1048577];

    fstream ofile,nfile;

    clock_t t;
    t = clock();
    ofile.open("big.txt",ios::out);
    srand(time(NULL));
    while(size--)
    {
        number = rand()% 1000;
        ofile << number << endl;
    }
    ofile.close();
    ofile.open("big.txt",ios::in);
    int k,u,v=1048577;
    s = 1048576*64;
    while(s > 0)
    {
        s = s - 1048576;
        nsize = 1048576;
        nfile.open(filename[k],ios::out);
    
        u = 1;

        while(nsize--)
        {
            ofile >> w[u];
                u++;
        }
    
        Merge_sort(w,1,v+1);
    
        nsize = 1048576;
        
        u = 1;
        
        while(nsize--)
        {
            nfile << w[u] << endl;
                u++;
        }
        
        k++;
        nfile.close();
    }
    ofile.close();
    int l = 0;
    fstream mer1,file1,file2,file3,file4,file5,file6,file7,file8;
    for (int i = 0; i < 64; i = i + 8)
    {
        file1.open(filename[i],ios::in);
        file2.open(filename[i+1],ios::in);
        file3.open(filename[i+2],ios::in);
        file4.open(filename[i+3],ios::in);
        file5.open(filename[i+4],ios::in);
        file6.open(filename[i+5],ios::in);
        file7.open(filename[i+6],ios::in);
        file8.open(filename[i+7],ios::in);
        mer1.open(merge4[l],ios::out);  
        l++;
        way8(file1,file2,file3,file4,file5,file6,file7,file8,mer1);
        file1.close();
        file2.close();
        file3.close();
        file4.close();
        file5.close();
        file6.close();
        file7.close();
        file8.close();
        mer1.close();
    }
    l = 0;  
    for (int i = 0; i < 8; i = i + 4)
    {
        file1.open(merge4[i],ios::in);
        file2.open(merge4[i+1],ios::in);
        file3.open(merge4[i+2],ios::in);
        file4.open(merge4[i+3],ios::in);
        mer1.open(merge2[l],ios::out);  
        l++;
        way4(file1,file2,file3,file4,mer1);
        file1.close();
        file2.close();
        file3.close();
        file4.close();
        mer1.close();
    }
    file1.open(merge2[0],ios::in);
    file2.open(merge2[1],ios::in);
    mer1.open(final,ios::out);  
    way2(file1,file2,mer1);
    file1.close();
    file2.close();
    mer1.close();
    t = clock() - t;
    printf ("Running time : %f seconds.\n",((float)t)/CLOCKS_PER_SEC);
    return 0;
}
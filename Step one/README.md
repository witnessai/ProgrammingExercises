# 1.最短路(Floyd、Dijstra,BellmanFord)  

## Floyd  
参考:  
http://baike.baidu.com/item/%E8%BF%AA%E6%9D%B0%E6%96%AF%E7%89%B9%E6%8B%89%E7%AE%97%E6%B3%95?fr=aladdin 



测试数据 教科书 P189 G6 的邻接矩阵 其中 数字 1000000 代表无穷大  
6  
1000000 1000000 10 100000 30 100  
1000000 1000000 5 1000000 1000000 1000000  
1000000 1000000 1000000 50 1000000 1000000  
1000000 1000000 1000000 1000000 1000000 10  
1000000 1000000 1000000 20 1000000 60  
1000000 1000000 1000000 1000000 1000000 1000000  
结果：  
D[0]   D[1]   D[2]   D[3]   D[4]   D[5]  
0   1000000   10     50     30     60  
    
        
    #include <iostream>  
    #include <cstdio>  
    #define MAX 1000000  
    using namespace std;  
    int arcs[10][10];//邻接矩阵  
    int D[10];//保存最短路径长度  
    int p[10][10];//路径  
    int final[10];//若final[i] = 1则说明 顶点vi已在集合S中  
    int n = 0;//顶点个数  
    int v0 = 0;//源点  
    int v,w;
    void ShortestPath_DIJ()
    {
         for (v = 0; v < n; v++) //循环 初始化
         {
              final[v] = 0; D[v] = arcs[v0][v];
              for (w = 0; w < n; w++) p[v][w] = 0;//设空路径
              if (D[v] < MAX) {p[v][v0] = 1; p[v][v] = 1;}
         }
         D[v0] = 0; final[v0]=0; //初始化 v0顶点属于集合S
         //开始主循环 每次求得v0到某个顶点v的最短路径 并加v到集合S中
         for (int i = 1; i < n; i++)
         {
              int min = MAX;
              for (w = 0; w < n; w++)
              {
                   //我认为的核心过程--选点
                   if (!final[w]) //如果w顶点在V-S中
                   {
                        //这个过程最终选出的点 应该是选出当前V-S中与S有关联边
                        //且权值最小的顶点 书上描述为 当前离V0最近的点
                        if (D[w] < min) {v = w; min = D[w];}
                   }
              }
              final[v] = 1; //选出该点后加入到合集S中
              for (w = 0; w < n; w++)//更新当前最短路径和距离
              {
                   /*在此循环中 v为当前刚选入集合S中的点
                   则以点V为中间点 考察 d0v+dvw 是否小于 D[w] 如果小于 则更新
                   比如加进点 3 则若要考察 D[5] 是否要更新 就 判断 d(v0-v3) + d(v3-v5) 的和是否小于D[5]
                   */
                   if (!final[w] && (min+arcs[v][w]<D[w]))
                   {
                        D[w] = min + arcs[v][w];
                       // p[w] = p[v];
                        p[w][w] = 1; //p[w] = p[v] +　[w]
                   }
              }
         }
    }
     
    
    int main()
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
             for (int j = 0; j < n; j++)
             {
                  cin >> arcs[i][j];
              }
        }
        ShortestPath_DIJ();
        for (int i = 0; i < n; i++) printf("D[%d] = %d\n",i,D[i]);
        return 0;
    }  


# 2.最小生成树  
## prim  
## kruscal

# 3.大数(高精度)加减乘除  
## 有符号的大整数加减法  
参考：  
http://blog.csdn.net/architect19/article/details/9498659  
## 大正整数的加减乘除  
参考：  
http://blog.csdn.net/tryitboy/article/details/38477983  
http://blog.csdn.net/luxiaoxun/article/details/7980618  

# 4.二分查找(代码可在五行以内)  
参考：
作者：LightGHLi
链接：https://www.zhihu.com/question/36132386
来源：知乎

对其进行分类：取整方式：向下取整 向上取整 （共2种）  
区间开闭：闭区间 左闭右开区间 左开右闭区间 开区间 （共4种）  
问题类型：  
对于不下降序列a，求最小的i，使得a[i] = key  
对于不下降序列a，求最大的i，使得a[i] = key  
对于不下降序列a，求最小的i，使得a[i] > key  
对于不下降序列a，求最大的i，使得a[i] < key  
对于不上升序列a，求最小的i，使得a[i] = key  
对于不上升序列a，求最大的i，使得a[i] = key  
对于不上升序列a，求最小的i，使得a[i] < key  
对于不上升序列a，求最大的i，使得a[i] > key（共8种）  
综上所述，二分查找共有 2*4*8 种写法。  
算法的目的是解决问题，下面以针对不下降序列a的4个问题为例，给出我认为效率较高，较为简洁的代码。  
对于不下降序列a，n为序列a元素的个数，key为关键字：  
1.求最小的i，使得a[i]=key,若不存在，则返回-1  

    int binary_search_1(int a[], int n, int key)  
    {  
        int m, l = 0, r = n-1;//闭区间[0, n-1]  
        while(l < r)  
        {  
            m = l+(r-l)>>2;//向下取整  
            if(a[m] < key) l = m+1;  
            else r = m;  
        }  
        if(a[r] == key) return r;  
        else return -1;  
    }
2.求最大的i,使得a[i]=key,若不存在，则返回-1  

    int binary_search_2(int a[], int n, int key)
    {
        int m, l = 0, r = n-1;//闭区间[0, n-1]
        while(l < r)
        {
            m = l+(r-l+1)>>2;//向上取整
            if(a[m] <= key) l = m;
            else r = m-1;
        }
        if(a[l] == key) return l;
        else return -1;
    }
3.求最小的i,使得a[i]>key,若不存在，则返回-1  

    int binary_search_3(int a[], int n, int key)
    {
        int m, l = 0, r = n-1;
        while(l < r)
        {
            m = l+(r-l)>>2;
            if(a[m]<=key) l = m+1;
            else r = m;
        }
        if(a[r] > key) return r;
        else return -1;
    }
4.求最大的i,使得a[i]\<key,若不存在，则返回-1  

    int binary_search_4(int a[], int n, int key)
    {
        int m, l = 0, r = n-1;
        while(l < r)
        {
            m = l+(r-l+1)>>2;
            if(a[m]\<key) l = m;
            else r = m-1;
        }
        if(a[l] < key) return l;
        else return -1;
    }
    
# 5.叉乘、判断线段相交，然后写个凸包  

参考：  
acm集合算法汇总 
http://www.360doc.com/content/13/1210/18/14060897_336141098.shtml  
计算集合算法分析(部分有代码)  
http://dev.gameres.com/Program/Abstract/Geometry.htm#矢量叉积


## 向量叉乘  
    struct POINT{
    TYPE x;
    TYPE y;
    TYPE z;
    POINT():x(0), y(0), z(0) {}
    POINT(TYPE _X, TYPE _Y, TYPE _Z):x(_X), y(_Y), z(_Z){}
    }
    
    //叉乘：矢量积a×b的计算结果是垂直于a，b向量的矢量，其大小|a×b|=|a|*|b|*sin(a, b)
    //,模值的集合意义是以a,b为边的平行四边形的面积，利用向量的叉乘可以计算多边形的面积
   
    //cross product of (o->a) and (o->b)
    TYPE Cross(const POINT &a, const POINT &b, const POINT &o)
    {return (a.x-o.x)*(b.y-o.y)-(b.x-o.x)*(a.y-o.y);}  

## 判断线段相交  


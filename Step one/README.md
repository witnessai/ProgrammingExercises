# 最短路(Floyd、Dijstra,BellmanFord)  

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


using namespace std;
#define MAX 50
bool isvalid(int x, int y, int n)
{
    if(x>=0&&x<n&&y>=0&&y<n)
    {
        return true;
    }
    return false;
}
void help(int a[MAX][MAX], int n)
{
    int dx[]={-1,0,1,0};
    int dy[]={0,1,0,-1};
    map<pair<int,int>,int> dist;
    for(int i=0;i<n;i++)
    {
        for(auto j=0;j<n;j++)
        {
            dist[make_pair(i,j)]=INT_MAX;
        }
    }
    set<pair<int,pair<int,int>>> s;
    s.insert(make_pair(a[0][0],make_pair(0,0)));
    dist[make_pair(0,0)]=a[0][0];
    while(!s.empty())
    {
        pair<int,pair<int,int>>p=*(s.begin());
        int weight = p.first;
        pair<int,int> coordinate = p.second;
        s.erase(s.begin());
        for(int i=0;i<4;i++)
        {
            int xset = coordinate.first+dx[i];
            int yset = coordinate.second+dy[i];
            if(isvalid(xset,yset,n))
            {
        if(weight+a[xset][yset]<dist[make_pair(xset,yset)])
                {
    auto l= s.find(make_pair(dist[make_pair(xset,yset)],make_pair(xset,yset)));
                    if(l!=s.end())
                    {
                        s.erase(l);
                    }
                    s.insert(make_pair(weight+a[xset][yset],make_pair(xset,yset)));
                    dist[make_pair(xset,yset)]=weight+a[xset][yset];
                }
            }
        }
    }
    cout<<dist[make_pair(n-1,n-1)]<<endl;
}
int main()
 {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
        int a[MAX][MAX];
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> a[i][j];
            }
        }
        help(a, n);
	}
	return 0;
}
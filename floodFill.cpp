/*NAME : Il Gioco dell'X*/
/*ID   : 260*/
/*Lang.: c++*/

#include<iostream>
#include<cstring>
#include<vector>

using namespace std;

vector<char> adj[10000];
int n,i,j,k,l,sum;
char ch[10000];
bool visit[201][201];
char output;

void fill(int r,int c)
{
	if(r<0||c<0||c>=adj[r].size()||adj[r][c]=='b'||visit[r][c]==true)
		return;

	visit[r][c]=true;
	fill(r-1,c-1);
	fill(r,c-1);
	fill(r+1,c);
	fill(r-1,c);
	fill(r,c+1);
	fill(r+1,c+1);
}

int main()
{
	int cs=1;
	while(cin>>n)
	{
		if(n==0)
			break;
		for(i=0;i<n;i++)
		{
			adj[i].clear();
			cin>>ch;
			for(j=0;j<n;j++)
			{
				adj[i].push_back(ch[j]);
			}
		}
		
		bool key=false;
		for(i=0;i<n;i++)
		{
			memset(visit,false,sizeof visit);
			if(adj[i][0]=='w')
				fill(i,0);
			for(j=0;j<n;j++)
			{
				if(visit[j][n-1]==true)
				{
					key=true;
					break;
				}
			}
			if(key==true)break;
		}
		if(key==true)
			cout<<cs++<<" W"<<endl;
		else
			cout<<cs++<<" B"<<endl;
	}
	return 0;
}


/*NAME : The Seasonal War*/
/*ID   : 352*/
/*Lana.: c++*/

#include<iostream>
#include<cstring>
#include<vector>

using namespace std;

vector<char > adj[150];
int row,col,i,j,k;
char ch[150];


void search(int r,int c)
{
	if(r<0||c<0||c>=adj[r].size()||adj[r][c]=='0')
		return;
	adj[r][c]='0';
	search(r-1,c-1);
	search(r+1,c+1);
	search(r-1,c+1);
	search(r+1,c-1);
	search(r-1,c);
	search(r+1,c);
	search(r,c-1);
	search(r,c+1);
}


int main()
{
	int css=0;
	while(cin>>row)
	{
		memset(adj,0,sizeof(adj));
		for(i=0;i<row;i++)
		{
			cin>>ch;
			for(j=0;j<row;j++)
			{
				adj[i].push_back(ch[j]);
			}
		}
		int sum=0;
		for(i=0;i<row;i++)
		{
			for(j=0;j<row;j++)
			{
				if(adj[i][j]=='1')
				{
					sum++;
					search(i,j);
				}
			}
		}
		css++;
		cout<<"Image number "<<css<<" contains "<<sum<<" war eagles."<<endl;
	}
	return 0;
}


/*NAME : Graph Connectivity*/
/*ID   : 459*/
/*Lang.: c++*/

#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>

using namespace std;

bool visit[26];
char ch[10];
char mx;
vector<int> adj[10000];
int i,j,k,l,len;

void dfs(int u)
{
	visit[u]=true;
	for(int m=0;m<adj[u].size();m++)
	{
		if(visit[adj[u][m]]==true)
			continue;
		dfs(adj[u][m]);
	}
}


int main()
{
	char temp[2];
	int tc;
	cin>>tc;
	cin.getline(temp,2);
	getchar();
	while(tc--)
	{
		cin>>mx;
		getchar();
		for(i=0;i<=mx-65;i++)
			adj[i].clear();
		while(cin.getline(ch,10))
		{
			len=strlen(ch);
			if(len==0)
				break;
			else
			{
				adj[ch[0]-65].push_back(ch[1]-65);
				adj[ch[1]-65].push_back(ch[0]-65);
			}
		}
		for(j=0;j<=(mx-65);j++)
			visit[j]=0;
		int	sum=0;
		for(j=0;j<=(mx-65);j++)
		{
			if(visit[j]==false)
			{
				dfs(j);
				sum++;
			}
		}
		cout<<sum<<endl;
		if(tc)
			cout<<endl;
	}
	return 0;
}


/*NAME : Wetlands of Florida*/
/*ID   : 469*/
/*Lang.: c++*/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cstdlib>
#include<vector>
#include<cmath>
#include<cctype>
#include<sstream>

using namespace std;

vector<char> adj[10000];

bool vis[100][100];
char ch[10000];
int row,col,i,j,k,l,a,b,cnt;
int len,sum;
char ctemp;



void dfs(int r,int c)
{
	if(r<0||c<0||c>=adj[r].size()||adj[r][c]=='L'||vis[r][c])
		return;
	sum++;
	vis[r][c]=true;
	for(int m=-1;m<2;m++)
	{
		for(int n=-1;n<2;n++)
		{
			if(m||n)
				dfs(r+m,c+n);
		}
	}

}

int main()
{
	int tc;
	bool blank=false;
	cin>>tc;
	getchar();
	getchar();
	while(tc--)
	{
		if(blank)
			cout<<endl;
		blank=true;
		row=0;
		while(cin.getline(ch,10000)&&strlen(ch)>0)
		{
			adj[row].clear();
			if(ch[0]=='W'||ch[0]=='L')
			{
				for(i=0;i<strlen(ch);i++)
				{
					adj[row].push_back(ch[i]);
				}
				row++;
			}
			else
			{
				sscanf(ch,"%d %d",&k,&l);
				memset(vis,false,sizeof(vis));
				sum=0;
				dfs(k-1,l-1);
				cout<<sum<<endl;

			}
		}
	}
	return 0;
}


/*NAME : Oil Deposits*/
/*ID   : 572*/
/*Lang.: c++*/


#include<iostream>
#include<cstring>
#include<vector>

using namespace std;

vector<char > adj[150];
int row,col,i,j,k;
char ch[150];


void search(int r,int c)
{
	if(r<0||c<0||c>=adj[r].size()||adj[r][c]=='*')
		return;
	adj[r][c]='*';
	search(r-1,c-1);
	search(r+1,c+1);
	search(r-1,c+1);
	search(r+1,c-1);
	search(r-1,c);
	search(r+1,c);
	search(r,c-1);
	search(r,c+1);
}


int main()
{
	while(cin>>row>>col)
	{
		if(row==0 && col==0)
			break;
		memset(adj,0,sizeof(adj));
		for(i=0;i<row;i++)
		{
			cin>>ch;
			for(j=0;j<col;j++)
			{
				adj[i].push_back(ch[j]);
			}
		}
		int sum=0;
		for(i=0;i<row;i++)
		{
			for(j=0;j<col;j++)
			{
				if(adj[i][j]=='@')
				{
					sum++;
					search(i,j);
				}
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}


/*NAME : The die is cast*/
/*ID   : 657*/
/*Lang.: c++*/

#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>

using namespace std;

vector<char> adj[10000];
char ch[10000];
int i,j,k,l,row,col;
int sum;


void dfs1(int r,int c)
{
	if(r<0||c<0||c>=adj[r].size()||adj[r][c]!='X')
		return;
	adj[r][c]='*';
	dfs1(r-1,c);
	dfs1(r+1,c);
	dfs1(r,c+1);
	dfs1(r,c-1);
}

void dfs(int r,int c)
{
	if(r<0||c<0||c>=adj[r].size()||adj[r][c]=='.')
		return;
	if(adj[r][c]=='X')
	{
		sum++;
		dfs1(r,c);
	}

	adj[r][c]='.';
	dfs(r-1,c);
	dfs(r+1,c);
	dfs(r,c+1);
	dfs(r,c-1);
}

int main()
{
	int cs=1;
	while(cin>>col>>row)
	{
		if(col==0&&row==0)
			break;
		for(i=0;i<row;i++)
		{
			cin>>ch;
			adj[i].clear();
			for(j=0;j<col;j++)
			{
				adj[i].push_back(ch[j]);
			}
		}
		vector<int> output;
		for(i=0;i<row;i++)
		{
			for(j=0;j<adj[i].size();j++)
			{
				if(adj[i][j]!='.')
				{
					sum=0;
					dfs(i,j);
					output.push_back(sum);
				}
			}

		}
		sort(output.begin(),output.end());
		cout<<"Throw "<<cs++<<endl;
		cout<<output[0];
		for(i=1;i<output.size();i++)
		{
			cout<<" "<<output[i];
		}
		cout<<endl<<endl;
	}
	return 0;
}


/*NAME : Lakes*/
/*ID   : 722*/
/*Lnag.: c++*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<cstring>

using namespace std;

vector<char> adj[100000];
char ch[10000];
int row,col;
int i,j,k,l,tc,len,sum;
bool visit[110][110];


void dfs(int r,int c)
{
	if(r<0||c<0||r>=j||c>=adj[r].size()||visit[r][c]||adj[r][c]=='1')
		return;
	sum++;
	visit[r][c]=true;
	for(int m=-1;m<2;m++)
	{
		for(int n=-1;n<2;n++)
		{
			if(m<0&&n==0||m==0&&n<0||m==0&&n>0||m>0&&n==0)
				dfs(r+m,c+n);
		}
	}
}


int main()
{	
	cin>>tc;
	
	while(tc--)
	{
		cin>>row>>col;
		getchar();
		j=0;
		while(cin.getline(ch,10000))
		{
			
			len=strlen(ch);
			if(len==0)
				break;
			else
			{
				adj[j].clear();
				for(k=0;k<len;k++)
				{
					if(ch[k]!=' ')
					adj[j].push_back(ch[k]);
				}
			}
			j++;
		}
		memset(visit,false,sizeof visit);
		sum=0;
		dfs(row-1,col-1);
		cout<<sum<<endl;
		if(tc)
			cout<<endl;
	}
	return 0;
}

/*NAME : Maze Exploration*/
/*ID   : 784*/
/*Lang.: c++*/

#include<iostream>
#include<cstring>
#include<vector>
#include<string>
#include<cstdio>

using namespace std;

vector<char > adj[10000];
int i,j,k,l;

void search(int r,int c)
{
	if(r<0||c<0||c>=adj[r].size()||adj[r][c]=='#'||adj[r][c]=='X')
		return;
	adj[r][c]='#';
	search(r-1,c-1);
	search(r+1,c+1);
	search(r-1,c+1);
	search(r+1,c-1);
	search(r-1,c);
	search(r+1,c);
	search(r,c-1);
	search(r,c+1);
}

bool end(char *c)
{
	int len=strlen(c);
	for(i=0;i<len;i++)
	{
		if(c[i]=='_')
			return true;
	}
	return false;
}

int main()
{
	char ch[1000];
	int tc;
	int len;
	string str;
	cin>>tc;
	getchar();
	while(tc--)
	{
		j=0;
		memset(adj,0,sizeof(adj));
		while(cin.getline(ch,1000))
		{
			len=strlen(ch);
			if(end(ch))
			{
				for(i=0;i<len;i++)
					adj[j].push_back(ch[i]);
				break;
			}
			for(i=0;i<len;i++)
				adj[j].push_back(ch[i]);
			j++;
		}
		for(i=0;i<j-1;i++)
		{
			for(k=0;k<adj[i].size();k++)
			{
				if(adj[i][k]=='*')
					search(i,k);
			}
		}
		for(i=0;i<j+1;i++)
		{
			for(k=0;k<adj[i].size();k++)
			{
				cout<<adj[i][k];
			}
			cout<<endl;
		}
	}
	return 0;
}


/*NAME : Grid Colouring*/
/*ID   : 785*/
/*Lang.: c++*/


#include<iostream>
#include<cstring>
#include<vector>
#include<cstdio>

using namespace std;

vector<char> adj[35];
char ch[85];
int i,j,k,l,row,len,temp;

void fill(int r,int c)
{
	if(r<0 ||c<0||c>=adj[r].size()||adj[r][c]=='X'||adj[r][c]==temp)
		return;
	adj[r][c]=temp;
	fill(r,c-1);
	fill(r,c+1);
	fill(r+1,c);
	fill(r-1,c);
}

bool check(char *str)
{
	for(i=0;i<strlen(str);i++)
	{
		if(str[i]=='_')
			return true;
	}
	return false;
}


int main()
{
	while(cin.getline(ch,85))
	{
		row=0;
		do
		{
			adj[row].clear();
			if(check(ch))
			{
				for(i=0;i<strlen(ch);i++)
				{
					adj[row].push_back(ch[i]);
				}
				break;
			}
			else
			{
				for(i=0;i<strlen(ch);i++)
				{
					adj[row].push_back(ch[i]);
				}
			}
			row++;
		}
		while(cin.getline(ch,85));
		for(i=0;i<row;i++)
		{
			for(j=0;j<adj[i].size();j++)
			{
				if(adj[i][j]!='X' && adj[i][j]!=' ')
				{
					temp=adj[i][j];
					adj[i][j]=' ';
					fill(i,j);
				}
			}
		}

		for(i=0;i<=row;i++)
		{
			for(j=0;j<adj[i].size();j++)
			{
				cout<<adj[i][j];
			}
			cout<<endl;
		}
	}
	return 0;
}

/*NAME : Counting Cells in a Blob*/
/*ID   : 871*/
/*Lang.: c++*/


#include<iostream>
#include<vector>
#include<cstring>
#include<string>
#include<cstdio>

using namespace std;


vector<char> adj[10000];
int i,j,k,l;
char ch[10000];
int len,row,col;
int sum;


void dfs(int r,int c)
{
	if(r<0 ||c<0||c>=adj[r].size()||adj[r][c]=='0')
		return;
	adj[r][c]='0';
	sum++;
	for(int m=-1;m<2;m++)
	{
		for(int n=-1;n<2;n++)
		{
			if(m||n)
				dfs(r+m,c+n);
		}
	}
}
int main()
{
	char temp[2];
	int mx,tc;
	cin>>tc;
	cin.getline(temp,2);
	getchar();
	while(tc--)
	{
		
		i=0;
		while(cin.getline(ch,10000))
		{
			len=strlen(ch);
			if(len==0)
				break;
			else
			{
				adj[i].clear();
				for(j=0;j<len;j++)
				{
					adj[i].push_back(ch[j]);
				}
			}
			i++;
		}
		row=i;
		col=j;

		mx=0;
		for(i=0;i<row;i++)
		{
			for(j=0;j<col;j++)
			{
				if(adj[i][j]=='1')
				{
					sum=0;
					dfs(i,j);
					if(mx<sum)
						mx=sum;
				}
			}
		}
		cout<<mx<<endl;
		if(tc)
			cout<<endl;
		}
	return 0;
}


/*NAME : Rank the Languages*/
/*ID   : 10336*/
/*Lang.: c++*/


#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

int row,col,cnt;
int i,j,k,l;
char ch[1000];
vector<char> mat[10000];
int arr[26];
char temp;

void fill(int r,int c)
{
	if(r<0 || c<0 || c>=mat[r].size() || mat[r][c]=='*' ||mat[r][c]!=temp)
		return;
	mat[r][c]='*';
	fill(r-1,c);
	fill(r+1,c);
	fill(r,c-1);
	fill(r,c+1);
}


int main()
{
	int mn,pos,tc,cs;
	cs=1;
	cin>>tc;
	while(tc--)
	{
		cin>>row>>col;
		for(i=0;i<row;i++)
		{
			mat[i].clear();
			cin>>ch;
			for(j=0;j<col;j++)
			{
				mat[i].push_back(ch[j]);
			}
		}
		for(i=0;i<26;i++)
			arr[i]=0;
		for(i=0;i<row;i++)
		{
			for(j=0;j<mat[i].size();j++)
			{
				if(mat[i][j]>=97 && mat[i][j]<=122 && mat[i][j]!='*')
				{
					arr[mat[i][j]-97]++;
					temp=mat[i][j];
					fill(i,j);
				}
			}
		}
		cout<<"World #"<<cs++<<endl;
		for(i=0;i<26;i++)
		{
				mn=0;
				for(j=0;j<26;j++)
				{
					if(mn<arr[j])
					{
						mn=arr[j];
						pos=j;
					}
				}
				if(mn>0)
					cout<<char(97+pos)<<": "<<mn<<endl;
				arr[pos]=0;
		}
	}
	return 0;
}


/*NAME : You want what filled?*/
/*ID   : 10946*/
/*Lang.: c++*/

#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>


using namespace std;

vector<char> adj[10000];

int row,col,i,j,k,l;
char ch[10000];
int sum;
char temp;


struct st
{
	int val;
	char alp;
}arr[10000];


bool func(st x,st y)
{
	if(x.val>y.val) return true;
	if(x.val==y.val && x.alp<y.alp ) return true;
	return false;
}



void fill(int r,int c)
{
	if(r<0||c<0||c>=adj[r].size()||adj[r][c]!=temp)
		return;
	adj[r][c]='.';
	sum++;
	fill(r,c+1);
	fill(r,c-1);
	fill(r+1,c);
	fill(r-1,c);
}

int main()
{
	int cs=1;
	while(cin>>row>>col)
	{
		if(row==0&&col==0)
			break;
		for(i=0;i<row;i++)
		{
			adj[i].clear();
			cin>>ch;
			for(j=0;j<col;j++)
			{
				adj[i].push_back(ch[j]);
			}
		}
		k=0;
		for(i=0;i<row;i++)
		{
			for(j=0;j<adj[i].size();j++)
			{
				sum=0;
				if(adj[i][j]!='.')
				{
					temp=adj[i][j];
					fill(i,j);
					arr[k].val=sum;
					arr[k].alp=temp;
					k++;
				}
			}
		}

		sort(arr+0,arr+k,func);
		cout<<"Problem "<<cs++<<":"<<endl;
		for(i=0;i<k;i++)
		{
			cout<<arr[i].alp<<" "<<arr[i].val<<endl;
		}
	}
	return 0;
}

/*NAME : Continents*/
/*ID   : 11094*/
/*Lang.: c++*/


#include<iostream>
#include<cstring>
#include<vector>
#include<cstdio>
#include<climits>

using namespace std;

vector<char> adj[10000];
char ch[10000];
int i,j,k,l,row,col,sum,src,dst,res;
char temp;
bool visit[10000][10000];


void dfs(int r,int c)
{
	if(r<0||c<0||c>=adj[r].size()||visit[r][c]==true||adj[r][c]!=temp)
		return;
	res++;
	visit[r][c]=true;
	for(int m=-1;m<2;m++)
	{
		for(int n=-1;n<2;n++)
		{
			if(m<0&&n==0||m==0&&n<0||m==0&&n>0||m>0&&n==0)
				dfs(r+m,(c+n+col)%col);
		}
	}

}

int main()
{
	while(cin>>row>>col)
	{
	
		for(i=0;i<row;i++)
		{
			adj[i].clear();
			cin>>ch;
			for(j=0;j<col;j++)
			{
				adj[i].push_back(ch[j]);
			}
		}
		memset(visit,false,sizeof visit);
		cin>>src>>dst;
		temp=adj[src][dst];
		sum=0;
		dfs(src,dst);
		sum=0;
		for(i=0;i<row;i++)
		{
			for(j=0;j<adj[i].size();j++)
			{
				if(adj[i][j]==temp && visit[i][j]==false)
				{
					res=0;
					dfs(i,j);
					if(sum<res)
						sum=res;
				}
			}
		}
		cout<<sum<<endl;
		getchar();
	}
	return 0;
}

/*NAME : Counting Stars*/
/*ID   : 11244*/
/*Lang.: c++*/

#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

char adj[200][200];
int row,col,i,j,k,l;


void dfs(int r,int c)
{
	if(r<0||c<0||c>=col||r>=row||adj[r][c]=='.')
		return;
	adj[r][c]='.';
	for(int m=-1;m<2;m++)
	{
		for(int n=-1;n<2;n++)
		{
			if(m||n)
				dfs(r+m,c+n);
		}
	}
}


int main()
{
	int sum;
	while(cin>>row>>col)
	{
		if(row==0 && col==0)
			break;
		
		for(i=0;i<row;i++)
		{
			for(j=0;j<col;j++)
				memset(adj,'0',sizeof adj);
		}


		for(i=0;i<row;i++)
		{
			for(j=0;j<col;j++)
			{
				cin>>adj[i][j];
			}
		}
		sum=0;
		for(i=0;i<row;i++)
		{
			for(j=0;j<col;j++)
			{
				if(adj[i][j]=='*')
				{
					if( adj[i-1][j-1] == '*'||
						adj[i+1][j+1] == '*'||
						adj[i-1][j+1] == '*'||
						adj[i+1][j-1] == '*'||
						adj[i][j-1]   == '*'||
						adj[i][j+1]   == '*'||
						adj[i-1][j]   == '*'||
						adj[i+1][j]   == '*')
						dfs(i,j);
					else
						sum++;
				}
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}

/*NAME : Square Sums*/
/*ID   : 11470*/
/*Lang.: c++*/


#include<iostream>

using namespace std;

int main()
{
	int arr[20][20],a,b;
	int sum,n,i,j,cs=1;
	while(cin>>n)
	{
		if(n==0)
			break;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
				cin>>arr[i][j];
		}
		cout<<"Case "<<cs++<<":";
		for(a=0,b=n-1;a<=b;a++,b--)
		{
			if(a==b)
			{
				cout<<" "<<arr[a][b];
				break;
			}
			sum=0;
			for(i=a;i<=b;i++)
				sum+=arr[a][i]+arr[b][i]+arr[i][a]+arr[i][b];
			sum-=arr[a][a]+arr[a][b]+arr[b][a]+arr[b][b];
			cout<<" "<<sum;
		}
		cout<<endl;
	}
	return 0;
}

/*NAME : Dominos 2*/
/*ID   : 11518*/
/*Lang.: c++*/

#include<iostream>
#include<vector>
#include<cstring>
#include<cstdlib>

using namespace std;

vector<int> adj[10001];
bool visit[10001];
int vertex,edge,src,dst,qry,dom,fall,temp;
int i,j,k,l,tc;


void dfs(int u)
{
	if(visit[u])return;
	fall++;
	visit[u]=true;
	for(int m=0;m<adj[u].size();m++)
	{
		if(visit[adj[u][m]]==false)
			dfs(adj[u][m]);
	}
}



void Input_Graph()
{
	cin>>tc;
	while(tc--)
	{
		cin>>vertex>>edge>>qry;
		for(i=0;i<=vertex;i++)
		{
			adj[i].clear();
			visit[i]=false;
		}
		for(i=0;i<edge;i++)
		{
			cin>>src>>dst;
			adj[src].push_back(dst);
		}
		fall=0;
		while(qry--)
		{
			
			cin>>dom;
			dfs(dom);
		}
		cout<<fall<<endl;
	}
}

int main()
{
	Input_Graph();
	return 0;
}

/*NAME : Poor Trade Advisor*/
/*ID   : 11749*/
/*Lang.: c++*/

#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<climits>
#define pi pair<int,int>

using namespace std;

vector< pair < int,pi > > edges;
int parent[1000010],used[1000010];
int i,j,k,l,p,q;
int vertex,edge,src,dst,wet,key;

int find(int u)
{
	if(parent[u]==u)
		return u;
	return parent[u]=find(parent[u]);
}


void Input_Graph()
{
	while(cin>>vertex>>edge)
	{
		if(vertex==0&&edge==0)
			break;
		edges.clear();
		for(i=0;i<edge;i++)
		{
			cin>>src>>dst>>wet;
			edges.push_back(make_pair(wet,make_pair(src,dst)));
		}
		sort(edges.begin(),edges.end());
		reverse(edges.begin(),edges.end());
		for(i=1;i<=vertex;i++)
		{
			parent[i]=i;
			used[i]=0;
		}
		key=edges[0].first;
		for(i=0;i<edge;i++)
		{
			if(edges[i].first==key)
			{
				p=find(edges[i].second.first);
				q=find(edges[i].second.second);
				if(p!=q)
					parent[p]=q;
			}
		}
		for(i=1;i<=vertex;i++)
		{
			p=find(i);
			used[p]++;
		}
		int mx=0;
		for(i=1;i<=vertex;i++)
		{
			if(mx<used[i])
				mx=used[i];
		}
		cout<<mx<<endl;
	}
}


int main()
{
	Input_Graph();
	return 0;
}


/*NAME : Battleships*/
/*ID   : 11953*/
/*Lang.: c++*/

#include<iostream>
#include<cstring>
#include<vector>

using namespace std;

vector<char> adj[10000];
char ch[10000];
int n,i,j,k,l,tc;
char temp;

void dfs(int r,int c)
{
	if(r<0||c<0||c>=adj[r].size()||adj[r][c]=='.')
		return;
	adj[r][c]='.';
	for(int m=-1;m<2;m++)
	{
		for(int n=-1;n<2;n++)
		{
			if(m<0&&n==0||m==0&&n<0||m==0&&n>0||m>0&&n==0)
				dfs(r+m,c+n);
		}
	}
}
int main()
{
	int tc;
	cin>>tc;
	for(k=1;k<=tc;k++)
	{
		cin>>n;
		for(i=0;i<n;i++)
		{
			adj[i].clear();
			cin>>ch;
			for(j=0;j<n;j++)
			{
				adj[i].push_back(ch[j]);
			}
		}
		int sum=0;
		for(i=0;i<n;i++)
		{
			for(j=0;j<adj[i].size();j++)
			{
				if(adj[i][j]=='x')
				{
					sum++;
					dfs(i,j);
				}
			
			}
		}
		cout<<"Case "<<k<<": "<<sum<<endl;
	}
	return 0;
}

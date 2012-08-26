//accepted

#include <stdio.h>
#include <assert.h>

#define MAXSLIDES 26

FILE *inp;
int n,l[MAXSLIDES][4],c[MAXSLIDES][2];
int caseno=1;
char edge[MAXSLIDES][MAXSLIDES],e[2*MAXSLIDES+2][2*MAXSLIDES+2];
int reach[2*MAXSLIDES+2],back[2*MAXSLIDES+2];

int read_data()
{
	int i,j;
	
	scanf("%d",&n);
	for(i=0;i<n;i++){
		for(j=0;j<4;j++) scanf("%d",l[i]+j);
	}
	for(i=0;i<n;i++) scanf("%d %d",c[i],c[i]+1);
	return n;
}

int inside(int i, int j)
{
	/* check whether number of border of slide */
	assert(!( (l[i][0] == c[j][0] || l[i][1] == c[j][0]) &&
		l[i][2] <= c[j][1] && c[j][1] <= l[i][3] ));
	assert(!( (l[i][2] == c[j][1] || l[i][3] == c[j][1]) &&
		l[i][0] <= c[j][0] && c[j][0] <= l[i][1] ));
	return (l[i][0] <= c[j][0] && c[j][0] <= l[i][1] &&
		l[i][2] <= c[j][1] && c[j][1] <= l[i][3]);
}

int matching()
{
	int i,j,ch,m=0;
	
	for(i=0;i<2*n+2;i++)
		for(j=0;j<2*n+2;j++)
			e[i][j] = 0;
		for(i=0;i<n;i++)
		{
			e[0][i+2] = 1;
			e[n+i+2][1] = 1;
			for(j=0;j<n;j++)
				e[i+2][j+n+2] = edge[i][j];
		}
		while(1)
		{
			reach[0] = 1;
			for(i=1;i<2*n+2;i++) reach[i] = 0;
			ch = 1;
			while(ch)
			{
				ch = 0;
				for(i=0;i<2*n+2;i++)
					if(reach[i])
						for(j=0;j<2*n+2;j++)
							if(e[i][j] && !reach[j])
							{
								ch = 1;
								reach[j] = 1;
								back[j] = i;
								break;
							}
			}
			if(reach[1])
			{
				m++;
				for(i=1;i>0;i=back[i])
				{
					e[back[i]][i] = 0;
					e[i][back[i]] = 1;
				}
				goto cont;
			}
			break;
cont: ;
		}
		return (m == n);
}

void process_data()
{
	int i,j,k,f;
	
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			edge[i][j] = inside(i,j);
		assert(matching());
		printf("Heap %d\n",caseno++);
		f = 0;
		int sign=0;
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				if(edge[i][j])
				{
					edge[i][j] = 0;
					if(!matching())
					{
						if(sign) printf(" ");
						sign=1;
						printf("(%c,%d)",i+'A',j+1); f = 1;
						for(k=0;k<n;k++) 
						{
							if(k != i) edge[k][j] = 0;
							if(k != j) edge[i][k] = 0;
						}
					}
					edge[i][j] = 1;
				}
				if(!f) printf("none");
				printf("\n\n");
}

int main()
{
	while(read_data())
		process_data();
	return 0;
}


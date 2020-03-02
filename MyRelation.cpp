#include<iostream>
#include<string.h>
using namespace std;

template<typename T>

class MyRelation
{
    
    
    public:
    T *s1;
    T *s2;
    bool ref=false,sym=false,ants=false,tra=false;
    int **result;
    T *r;
    int n,m=-1,size;

    MyRelation(int a,int s)
    {
        n=a;
        s1=new T[n];
        inputSet();
		size=2*s;
        r=new T[size];
        result=new int*[n];

        for(int i=0;i<n;i++)
        {
            result[i]=new int[m];
        }
        cout<<"enter your relation is : "<<endl;
        inputRelation();
        set01();
       /* for(int i=0;i<n;i++)
        {
	    	for(int j=0;j<m;j++)
        		cout<<result[i][j];
        	cout<<endl;
        }*/
    }

    MyRelation(int a,int b,int size)
    {
        n=a;m=b;
        s1=new T[n];
        s2=new T[m];
		this->size=2*size;
        r=new T[size];
        result=new int*[n];
        for(int i=0;i<n;i++)
        {
            result[i]=new int[m];
        }
        
        inputSet();
        cout<<"enter your relation is "<<endl;
        inputRelation();
        set01();
       /* for(int i=0;i<n;i++)
        {
	    	for(int j=0;j<m;j++)
        		cout<<result[i][j];
        	cout<<endl;
        }*/
    }
    
    
	
    void set01()
    {
    	bool t=true;
        //0-1 in matrix
        
        for(int i=0;i<n;i++)
        {
        	for(int j=0;j<n;j++)
        	{
        		for(int k=0;k<size;k+=2)
        		{
        			if(s1[i]==r[k] && s1[j]==r[k+1])
                    {
        				result[i][j]=1;
                        break;
                    }
        			else
        				result[i][j]=0;
				}
			}
		}        
        
        int copy1[n][m];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            	copy1[i][j]=result[i][j];
        }
    }
    
    void reflexive()
    {
        ref=true;
        for(int i=0;i<n;i++)
        {
                if(result[i][i]!=1)
                {
                    ref=false;
                    break;
                } 
        }    
        if(ref==false)
            cout<<"it is not a reflexive relation "<<endl;
        
        if(ref==true)
            cout<<"it is a reflexive relation "<<endl;
        
    }
    void symmetric()
    {
        sym=true;
        int copy1[n][m];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                 copy1[i][j]=result[i][j];
            }
               

        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i!=j)
                {
                    if(copy1[i][j]!=copy1[j][i])
                    {
                        sym=false;
                        break;
                    }     
                }  
            }
            if(!sym)
            	break;
        }
            if(sym==true)
            	cout<<"it is a symmetric relation "<<endl;
			
            else
                cout<<"it is not a symmetric relation "<<endl;
        
    }
    void antisymmetric()
    {
        ants=true;
        int copy1[n][m];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                 copy1[i][j]=result[i][j];
            }
               

        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i!=j)
                {
                    if(copy1[i][j]=copy1[j][i])
                    {
                        ants=false;
                        break;
                    }     
                }  
            }
            if(!ants)
            	break;
        }
            if(ants==true)
            	cout<<"it is a anti-symmetric relation "<<endl;
			
            else
                cout<<"it is not a anti-symmetric relation "<<endl;

    }

    void inputSet()
    {
        cout<<"Enter your first set"<<endl;
        for(int i=0;i<n;i++)
            cin>>s1[i];
        cout<<"Your one set is "<<endl;
        cout<<"{";
        for(int i=0;i<n;i++)
        {
            cout<<s1[i];
            if(i<n-1)
                cout<<",";
        }
        cout<<"}"<<endl;
        
        if(m>0)
        {
            cout<<"Enter your first set"<<endl;
            for(int i=0;i<n;i++)
                cin>>s2[i];
            cout<<"Your second set is "<<endl;
            cout<<"{";
            for(int i=0;i<n;i++)
            {
               cout<<s2[i];
               if(i<n-1)
                cout<<",";
            }
            cout<<"}"<<endl;
        }
        else 
        {
        	m=n;
		}

    }

    void inputRelation()
    {
        for(int i=0;i<size;i++)
        {
                cin>>r[i];
        }
        cout<<"\nyour relation is : \n{";
        for(int i=0;i<size;i=i+2)
        	cout<<"("<<r[i]<<", "<<r[i+1]<<"),";
        cout<<"\b}\n";
    }
    
    void reflexiveClosure()
    {
        if(!ref)
        {
            cout<<"\n{";
            for(int i=0;i<n;i+=2)
            {
                cout<<"("<<r[i]<<","<<r[i+1] <<"),";
            }
            for(int i=0;i<n;i++)
            {
                if(result[i][i]!=1)
                {
                    cout<<",("<<s1[i]<<","<<s1[i]<<")";
                    if(i<n-1)
                        cout<<",";
                } 
            }
            cout<<"}\n"<<endl;
        }
        else
        cout<<"\nNo reflexive closure , Relation is reflexive "<<endl;
    }

    void symmetricClosure()
    {
        int copy1[n][m];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                copy1[i][j]=result[i][j];
        }
        if(sym)
        {
            cout<<"\n{";
            for(int i=0;i<2*n;i+=2)
            {
                    cout<<"("<<r[i]<<","<<r[i+1]<<"),";
            }
            for(int i=0;i<n;i++)
            {
                for(int j=0;i<m;j+=2)
                {
                    if(i!=j && copy1[i][j]==1 && copy1[j][i]==0)
                    {
                        cout<<",("<<s1[j]<<","<<s1[i]<<")";
                        if(i<n-1)
                            cout<<",";
                        copy1[j][i]=1;
                    } 
                }
            }
            cout<<"}"<<endl;
        }
        else
            cout<<"\nNo symmetric closure , Relation is symmetric "<<endl;
    }
    void equivalence()
    {
        if(ref && sym && tra)
            cout<<"\nIt is an equivalence reletion "<<endl;
    
    	else
        cout<<"\nIt is not an equivalence reletion "<<endl;
	}
    void display()
    {
        cout<<"\n{";
            for(int i=0;i<n;i+=2)
            {
                    cout<<"("<<r[i]<<","<<r[i+1]<<"),";
            }
            cout<<"}\n";
    }
    void transitive()
    {
        tra=true;
        int copy1[n][m];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                copy1[i][j]=result[i][j];
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(copy1[i][j]==1)
                {
                    for(int k=0;k<m;k++)
                    {
                        if(copy1[j][k]==1)
                        {
                            if(copy1[i][k]!=1)
                            {
                                tra=false;
                                break;
                            }
                        }
                    }
                }
                if(!tra)
                    break;
            }
            if(!tra)
                break;
        }
        if(tra)
            cout<<"\nIt is a trnsitive relation "<<endl;
        else
            cout<<"\nIt is not a trnsitive relation"<<endl;
    }


    void transitiveExtension()
    {
        int copy1[n][m];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                copy1[i][j]=result[i][j];
        }
        
        int copy2[n][m];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                copy2[i][j]=copy1[i][j];
        }

        if(!tra)
        {
            int z=0;
            while(z<n)
            {
                for(int i=0;i<n;i++)
                {
                for(int j=0;j<m;j++)
                {
                    if(copy1[i][j]==1)
                    {
                        for(int k=0;k<m;k++)
                        {
                            if(copy1[j][k]==1)
                            {
                                copy2[i][k]=1;
                            }
                        }
                    }
                }
                }
                for(int i=0;i<n;i++)
                {
                    for(int j=0;j<m;j++)
                        copy1[i][j]=copy2[i][j];
                }
                z++;
            }
            cout<<"\n{";
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<2*n;j+=2)
                {
                    if(copy1[i][j]==1)
                        cout<<"("<<s1[i]<<","<<s1[j]<<"),";
                }
            }
            cout<<"}"<<endl;
        }
        else    
            cout<<"\nNo transitive closure , It is a transitive relation "<<endl;
    }


    void warshall()
    {
        int copy1[n][m];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                copy1[i][j]=result[i][j];
        }
        
        int copy2[n][m];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                copy2[i][j]=copy1[i][j];
        }

        if(!tra)
        {
            int z=0;
            while(z<n)
            {
                for(int i=0;i<n;i++)
                {
                for(int j=0;j<m;j++)
                {
                    if(copy1[i][j]==1)
                    {
                        for(int k=0;k<m;k++)
                        {
                            if(copy1[j][k]==1)
                            {
                                copy2[i][k]=1;
                            }
                        }
                    }
                }
                }
                for(int i=0;i<n;i++)
                {
                    for(int j=0;j<m;j++)
                        copy1[i][j]=copy2[i][j];
                }
                z++;
            }
            cout<<"\n{";
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<2*n;j+=2)
                {
                    if(copy1[i][j]==1)
                        cout<<"("<<s1[i]<<","<<s1[j]<<"),";

                }
            }
            cout<<"}"<<endl;
        }
        else    
            cout<<"\nNo transitive closure , It is a transitive relation "<<endl;

    }
    void partialOrder()
    {
        if(ref && ants && tra)
        cout<<"It is a Partial odering relation "<<endl;
        else
        cout<<"It is not a Partial odering relation "<<endl;
    }   
};


template<typename T>
void set(T a)
{	
    int choice,n,m,size;
    	cout<<"\t\t 1 for relation on a set "<<endl;
        cout<<"\t\t 2 for reletion between two set "<<endl;
        
        cout<<"Enter your choice : ";
        cin>>choice;
        
    switch(choice)
    {
    	case 1:
        {
        	cout<<"Enter the size of set : ";
            cin>>n;
            cout<<"Enter the size of relation :";
            cin>>size;
            MyRelation<T> a(n,size);
            a.reflexive();
            a.symmetric();
            a.antisymmetric();
            a.transitive();
            a.reflexiveClosure();
            a.symmetricClosure();
            cout<<"trnsitive closure by warshall algorithm "<<endl;
            a.warshall();
            cout<<endl;
            cout<<"transitive closure by transitive extension "<<endl;
            a.transitiveExtension();
            cout<<endl;
            a.equivalence();
            a.partialOrder();

        }
			break;
		
		case 2:
		{
			cout<<"Enter the size of first set : ";
            cin>>n;
            cout<<"\nEnter the size of second set : ";
            cin>>m;
            cout<<"Enter the size of relation :";
            cin>>size;
            MyRelation<T> c(n,m,size);
            c.display();
		}
        	break;
			
		default :
			cout<<"Invalid choice "<<endl;
	}
}

int main()
{	
    int choice2;
    double a=5.0;
    string g="Gaurav";
    char h='A';
    do 
     {
     	cout<<"\nEnter 1 for int element in a set "<<endl;
        cout<<"Enter 2 for character element in a set "<<endl;
        cout<<"Enter 3 for double type element "<<endl;
        cout<<"Enter 4 for string type element "<<endl;
        
        cout<<"Enter your type : ";
        cin>>choice2;
        switch(choice2)
        {
        	case 1:
        		set(choice2);
        		break;
        	case 2:
        		set(h);
        		break;
        	case 3:
        		set(a);
        		break;
        	case 4:
        		set(g);
        		break;
        		
        	default:
        			cout<<"Invalid choice"<<endl;
        		
		}
		
        cout<<"\nDo you want to continue y/n : ";
        cin>>h;
    
    }while(h=='y');
    return 0;
}
template class MyRelation<char>;
template class MyRelation<int>;
template class MyRelation<double>;
template class MyRelation<string>;

#include <iostream>

using namespace std;

int main(void){
    int i,j,t;
    char url[65];
    cin>>t;
    for(j=1;j<=t;j++){
        cin>>url;
        cout<<"URL #"<<j<<endl;
        cout<<"Protocol = ";
        for(i=0;;i++){
            if(url[i]==':'){
                cout<<endl;
                break;
            }
            cout<<url[i];
        }
        cout<<"Host     = ";
        for(i+=3;;i++){
            if(url[i]==':'){
                cout<<endl;
                cout<<"Port     = ";
                for(i++;;i++){
                    if(url[i]=='/'){
                        cout<<endl;
                        cout<<"Path     = ";
                        for(i++;url[i]!='\0';i++) cout<<url[i];
                        cout<<endl;
                        break;
                    }
                    else if(url[i]=='\0'){
                        cout<<endl;
                        cout<<"Path     = <default>"<<endl;
                        break;
                    }
                    else cout<<url[i];   
                }  
                break;                           
            }
            else if(url[i]=='/'){
                cout<<endl;
                cout<<"Port     = <default>"<<endl;
                cout<<"Path     = ";
                for(i++;url[i]!='\0';i++) cout<<url[i];
                cout<<endl;
                break;
            }
            else if(url[i]=='\0'){
                cout<<endl;
                cout<<"Port     = <default>"<<endl;
                cout<<"Path     = <default>"<<endl;
                break;
            }
            else cout<<url[i];
        }
        cout<<endl;
    }
    return 0;
}
                
                
        
        

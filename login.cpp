#include<iostream>
#include<fstream>
#include<string>
using namespace std;
const char *lol;
class loginfo
{
public:
    void login(void)
    {
        cout<<"Enter Username: "<<endl;
        cin>>userTyped;
        if(userTyped==defaultUser)
        {
            cout<<"\n";
            cout<<"Enter Password: "<<endl;
            cin>>passwordTyped;
            passwordTyped=getFile(lol);
            if(passwordTyped==defaultPassword)
            {
                acess=true;
                cout<<"Welcome xD!"<<endl;
            }
            else
            {
                cout<<"Password Wrong !"<<endl;
                if(passwordTyped.length()>defaultPassword.length())
                {
                    cout<<"Too long!"<<endl;
                }
                else if(passwordTyped.length()<defaultPassword.length())
                {
                    cout<<"Too short!"<<endl;
                }
                
                login();
            } 
        }
        else
        {
            cout<<"Who You're kidding !"<<endl;
            login();
        }  
    }     
    string getFile(const char* fileName)
    {
        string line;
        fstream file;

        file.open(fileName, ios::in);
        if(file.is_open())
        {
            getline(file, line);
        }
        file.close();

        return line;
        
    }
private:
    string defaultUser="user";
    string defaultPassword="momo";
    string userTyped;
    string passwordTyped;
    bool acess=true;
};
int main(int argc,char** argv)
{
    loginfo logobj;
    logobj.login();
    return 0;
}
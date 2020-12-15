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


        int e;

        file.open(fileName, ios::in);
        
        while(1)
        {
            file >> e;
            if(e == 0)
            {
                file.close();
                return line;
            }
            line += (char)decrypt(e);
        }

        file << "0";
        file.close();

        return line;
        
    }
    void saveFile(string line, const char* fileName)
    {
        fstream file;
        file.open(fileName, ios::out);

        for(int i = 0; i < line.length(); i++)
        {
            file << encrypt(line[i]);
            file << "\n";
            
        }

        file << "0";
        file.close();
    }
    int encrypt(int letter)
    {
        return letter + 3;   
    }
    int decrypt(int letter)
    {
        return letter - 3;
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
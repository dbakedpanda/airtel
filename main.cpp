#include <bits/stdc++.h>
using namespace std;

vector<string> logging;
vector<string> CommonWords(vector<string>temp1,vector<string>temp2)
{
    logging.push_back("Entered the function CommonWords()");
    map<string,bool>map;
    vector<string>ans;
    for(unsigned int i=0;i<temp1.size();i++)
    {
        string temp;
        for(unsigned int j=0;j<temp1[i].length();j++)
        {
            if((temp1[i][j]>='a'&&temp1[i][j]<='z')||(temp1[i][j]>='A'&&temp1[i][j]<='Z'))
            {
                if(temp1[i][j]>='A'&&temp1[i][j]<='Z')
                {
                    temp1[i][j]+=-'A'+'a';
                }
                temp.push_back(temp1[i][j]);
            }
        }
        map[temp]=1;
    }

    for(unsigned int i=0;i<temp2.size();i++)
    {
        string temp;
        for(unsigned int j=0;j<temp2[i].length();j++)
        {
            if((temp2[i][j]>='a'&&temp2[i][j]<='z')||(temp2[i][j]>='A'&&temp2[i][j]<='Z'))
            {
                 if(temp2[i][j]>='A'&&temp2[i][j]<='Z')
                {
                    temp2[i][j]+=-'A'+'a';
                }
                temp.push_back(temp2[i][j]);
            }
        }
        if(map[temp]==1) ans.push_back(temp);
    }
    logging.push_back("Exit function CommonWords()");
    return ans;
}
int main()
{
   int n;
   cout<<"Number of files to be used ?"<<endl;
   cin>>n;
   logging.push_back("");
   try{
   if(n<2)
    throw 1;
   if(n>4)
    throw 9;
   vector<vector<string> >vec(n);
   vector<string>ans;
   int i=0;
   while(i<n)
   {
       string name;
       cout<<"Enter file name"<<endl;
       cin>>name;
       string temp;
       ifstream infile1;
           infile1.open(name.c_str());
           if(!infile1)
           throw 0;

           logging.push_back("Reading"+name);
           while(infile1 >> temp)
           {
               vec[i].push_back(temp);
           }
           infile1.close();
           logging.push_back("Closing"+name);
        i++;
   }

   ans=CommonWords(vec[0],vec[1]);

   int j=2;
   while(j<n)
   {
       ans=CommonWords(ans,vec[j]);
       j++;
   }

   ofstream output_file("answer.txt");
   ostream_iterator<string> output_iterator(output_file, "\n");
   copy(ans.begin(), ans.end(), output_iterator);

   }
   catch(int ex){
       if(ex==1)
       {
           logging.push_back("Number of required files are more than available::err 001");
           cout<<"Directory has lesser files";
       }
       if(ex==9)
       {
           logging.push_back("Number of required files are less than minimum required::err 009");
           cout<<"Number of files cannot be less than 2";
       }
       if(ex==0)
       {
           logging.push_back("File doesnot exists::err 000");
           cout<<"Could not open file";
       }
   }
   ofstream log;
   log.open("log.txt");
   for(unsigned int k=0;k<logging.size();k++)
   {
       log<<logging[k];
       log<<endl;
   }
   return 0;
}

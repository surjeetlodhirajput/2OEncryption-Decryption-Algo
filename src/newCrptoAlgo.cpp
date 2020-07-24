#include<iostream>
#include<cstring>
#include<vector>
#include<fstream>
using namespace std;
int string_to_int(string value,int n)
{ int sum=0;
	for(int i=0;i<n;i++)
	{
		sum+=(int)value[i];
	}
	return sum;
}
 void banner()
  {
  	cout<<endl<<"         [#]      __2_DOT ENCRYPTION METHOD__        [#]              "<<endl<<endl;
  	cout<<"# BY..... "<<endl;
cout<<"		sssss	ll	rrrrrrr	    "<<endl;
cout<<"		s	ll      rr   rr     "<<endl;
cout<<"		sssss	ll	rrrrrrr	    "<<endl;
cout<<"		    s   ll	rr rr       "<<endl;
cout<<"		sssss	llllll  rr   rr     "<<endl;
cout<<endl;
 cout<<"[*] FOR ANY QUERY CONTACT AT \"SURJEETRAJPUT433@GMAIL.COM\" [*]"<<endl;

  }
  void smiley()
  {	cout<<endl;
  		cout<<"------------------------------------------------------------------"<<endl;   
cout<<"|                         0 0 0 0 0                               |"<<endl;
cout<<"|                       0          0                              |"<<endl;
cout<<"|                      0            0                             |"<<endl;
cout<<"|                     0              0                            |"<<endl;
cout<<"|                     0  <|      |>  0                            |"<<endl;
cout<<"|                     0      |       0                            |"<<endl;
cout<<"|                     0              0                            |"<<endl;
cout<<"|                     0  \\_______/  0                             |"<<endl;
cout<<"|                      0           0                              |"<<endl;
cout<<"|                        0 0 0 0 0                                |"<<endl;
cout<<"------------------------------------------------------------------"<<endl;
	
	cout<<endl<<endl;
  }
  class ENCRYPTION{
  	string value;
  	int str_len;
  	string new_value;
  	vector<int> str_value;
  	public:
  	ENCRYPTION(string val,int len):value(val),str_len(len)
  	{
  	 str_value;
	int i=0;
	while(i<str_len)
	{
	 str_value.push_back((int)value[i]);
	 i++;
	} 
	for(int j=0;j<str_len;j++)
	{
		int sum=0;
		sum=rand()%str_value[j];
		new_value=new_value+to_string(sum)+".";
		new_value=new_value+to_string(abs(sum-str_value[j]))+".";
	}
	}
	void DOUBLE_ENCRYPT(string password)
	{
		int pass_len=password.length();//taking the password from the user
	int key=string_to_int(password,pass_len);//creating key
	int new_value_len=new_value.length();
	for(int o=0;o<new_value_len;o++)
	{
		if(o%3==2)
		{
		int converting=(int)new_value[o];
		converting=converting+key;
		new_value[o]=(char)converting;		
		}
	}

	}
	void saving_to_file(string name)
	{
	ofstream file;
	file.open(name);
	file<<new_value;
	file.close();
	}
  	};
main()
{
	banner();
	string value;
	cout<<endl<<endl<<endl<<"[*] ENTER YOUR MESSAGE OR PLAINTEXT WHICH YOU WANT TO ENCRYPT [*]"<<endl;
	getline(cin,value);
 	int str_len=value.size();
	ENCRYPTION *encrypt=new ENCRYPTION(value,str_len);
	system("cls");
	banner();	
	string password;
	cout<<endl<<endl<<endl<<"[*]  ENTER THE SECRET PASSWORD TO DOUBLE PROTECTION AND ENCRYPT YOUR TEXT [*]"<<endl;
	getline(cin,password);
	encrypt->DOUBLE_ENCRYPT(password);
	string name;
	system("cls");
	banner();
	cout<<endl<<endl<<endl<<"[**] ENTER THE FILENAME IN WHICH YOU WANT TO SAVE THE CIPHER [**]"<<endl;
	cin>>name;
	encrypt->saving_to_file(name);
	system("cls");
	banner();
	cout<<endl<<"[**] FILE ENCRYPTED AND SAVE SUCCESSFULLY IN THE FILE [**]"<<endl<<endl;
	smiley();
	delete encrypt;
}

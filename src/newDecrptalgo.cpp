#include<bits/stdc++.h>
using namespace std;
int string_to_int(string pass,int n)
{
	int i=0,sum=0;
	while(i<n)
	{
		sum+=(int)pass[i];
		i++;
	}
	return sum;
}
  void smiley()
  {	cout<<endl<<endl;
  		cout<<"------------------------------------------------------------------"<<endl;   
cout<<"|                         0 0 0 0 0                               |"<<endl;
cout<<"|                       0          0                              |"<<endl;
cout<<"|                      0            0                             |"<<endl;
cout<<"|                     0              0                            |"<<endl;
cout<<"|                     0  <|      |>  0                            |"<<endl;
cout<<"|                     0      |       0                            |"<<endl;
cout<<"|                     0              0                            |"<<endl;
cout<<"|                     0  \\_______/  0                            |"<<endl;
cout<<"|                      0           0                              |"<<endl;
cout<<"|                        0 0 0 0 0                                |"<<endl;
cout<<"------------------------------------------------------------------"<<endl;
	
	cout<<endl<<endl;
  }
 void banner()
  {
  	cout<<"# BY..... "<<endl;
cout<<setw(15)<<"		sssss	ll	rrrrrrr	    "<<endl;
cout<<setw(15)<<"		s	ll      rr   rr     "<<endl;
cout<<setw(15)<<"		sssss	ll	rrrrrrr	    "<<endl;
cout<<setw(15)<<"		    s   ll	rr rr       "<<endl;
cout<<setw(15)<<"		sssss	llllll  rr   rr     "<<endl;
cout<<endl;
cout<<"[*] FOR ANY QUERY CONTACT AT \"SURJEETRAJPUT433@GMAIL.COM\" [*]"<<endl<<endl;
  }
class Decrypt
  {
  	private:
  		//data mebers in the file for storing the permament infirmation on from the fle and copy  to the user 
  		string value;
  		vector<int> vec;//for storing the the converted ineteger value into the vector
  		public:
  			Decrypt()
  			{
			}
			~Decrypt()
  			{
			}
  			
  			//functions
void copy_information_from_file()//first function to copyinformaton form file
{
	string file_name;
ifstream file;
first:
getline(cin,file_name);
file.open(file_name);//By default the text file will get opened
if(file.fail())
		{
cout<<endl<<endl<<"[*] ERROR IN OPENING THE FILE [*]"<<endl<<endl;
cout<<endl<<endl<<"[*] ENTER A VALID FILE NAME [*]"<<endl<<endl;
goto first;
		}
	while(!file.eof())
	{	 //char copy;
	 file>>value;
	 //value+=copy;
	
	}
	
	file.close();
}
void decrypting_double_protection(string password )//second function 
{
int key=0;//for storing after coonversion of password into int
int password_len=password.length();
key=string_to_int(password,password_len); 
int value_len=value.length();
for(int o=0;o<value_len;o++)//loop for extracting the original decryption after removing the [assword encryption
{
		if(o%3==2)
{
		int converting=(int)value[o];
		converting=converting-key;
		value[o]=(char)converting;		
}
} 	
}
void show_perfect()
{
	if(value[value.length()-1]=='.')
	cout<<endl<<" OK! FILE IS ENCRYPTED BY 2_DOT ENCRYPTION ALGORITHM"<<endl<<endl;
	else{
	cout<<endl<<"[*] FILE IS NOT ENCRYPTEDBY 2_DOT ENCRYPTION METHOD  AND THIS ALGORITHM WILL NOT WORK FOR IT"<<endl;
	}
}
void extracting_original_value()//third function for extracting the original vlaue from the stored container
{
int value_len=value.length();//this is the length of the new string
string new_value;//till now it is not use 
int i=0;
while(i<value_len)
{	
int dot_come=0,sum_both=0;
	string manip;
	int r=0,sum=0;
	while(dot_come!=2)
	{	if(value[i]!='.'){
		manip+=value[i++];
	}
		else if(value[i++]=='.')
		{	dot_come++;	
			stringstream s(manip);
			s>>r;
			sum+=r;
			manip="";
		}	
		
	}
	vec.push_back(sum);
}
}
void show_cipher_text()//forth fucnction for showing the seved value
{
for(auto it:vec)
cout<<(char)it;
cout<<endl;	
}
void storig_in_file(string file_name)
{
ofstream file1;
file1.open(file_name);
for(auto it:vec)
file1<<(char)it;
file1.close();
cout<<endl;
}
bool return_()
{
cout<<endl<<"[*] WANT TO STORE THE INFORMATION IN THE FILE [*]"<<endl<<endl;
cout<<endl<<"[#] 1. YES \n[#] 2. NO \n"<<endl;
int n;
cin>>n;
if(n==1)
return true;
else
return false;	
 } 
};
int main()
{	
Decrypt* decrypt=new Decrypt();
banner();
string password;
cout<<endl<<endl<<"[*] ENTER THE FILENAME WHICH YOU WANT TO DECRYPT !!!"<<endl<<endl;

decrypt->copy_information_from_file();
system("cls");
banner();
cout<<endl<<endl<<"[#] ENTER THE SECRET PASSWORD TO DECRYPT THE FILE [#]"<<endl<<endl<<endl;
getline(cin,password);
decrypt->decrypting_double_protection(password);
decrypt->extracting_original_value();
system("cls");
banner();
decrypt->show_perfect();
cout<<endl<<endl<<endl<<"[*] DECRYPTED CIPHERTEXT [*]" <<endl<<endl<<endl;
decrypt->show_cipher_text();
if(decrypt->return_()==true){
 string name="";
cout<<endl<<"[*] ENTER THE FILE NAME IN WHICH YOU WANT TO SAVE FILE[*] "<<endl<<endl<<endl;
cin.ignore();
getline(cin,name);
decrypt->storig_in_file(name);
system("cls");
banner();
cout<<"[**] FILE DECRYPTED AND SAVE SUCCESSFULLY IN THE FILE [**]"<<endl;
smiley();
}
delete decrypt;
return 0;
}

#include<iostream>
#include<fstream>
#include<string>
#include<string.h>
#include<cstring>
#include<conio.h>
#include<stdlib.h>
#include<iomanip>
#include<sstream>

using namespace std;
char fname[20]="Music.txt";
struct record
{
	char id[50];
    char name[50];
    char artist[50];
    char genre[50];
    char album[50];
    char price[20];
    char quantity[20];
    char nosold[20];
};
class store_data
{
public:
	void pack(record r);
	record unpack(char a[]);
    void CreateOrder();
    void FindMusic();
    void SoldItems();
    void ItemStock();
    void AllItems();
    void AddNewItem();
    void EditItem();
    void RemoveItem();
};
void store_data::pack(record r)
{
	fstream fp;
	fp.open(fname,ios::out|ios::app);
	if(fp.fail())
	{
		cout<<"\n\n\t\t==========================================="<<endl;
		cout<<"\t\t\t~~~ ERROR FILE!! ~~~\n\t\t\t~~~ PLEASE CHECK AGAIN!! ~~~"<<endl;
		cout<<"\t\t==========================================="<<endl;
		exit(0);
	}
	char buff[50];
	strcpy(buff,r.id);
	strcat(buff,"|");
	strcat(buff,r.name);
	strcat(buff,"|");
	strcat(buff,r.artist);
	strcat(buff,"|");
	strcat(buff,r.genre);
	strcat(buff,"|");
	strcat(buff,r.album);
	strcat(buff,"|");
	strcat(buff,r.price);
	strcat(buff,"|");
	strcat(buff,r.quantity);
	strcat(buff,"|");
	strcat(buff,r.nosold);
	strcat(buff,"|");
	for(int i=0;i<60-strlen(buff);i++)
	      strcat(buff,"|");
	fp<<buff<<endl;
	fp.close();
}
record store_data::unpack(char buff[])
{
	record r;
	int i=0,j=0;
	while(buff[j]!='|')
	{
		r.id[i++]=buff[j++];
	}
	r.id[i]='\0';
	i=0;
	j++;
	while(buff[j]!='|')
	{
		r.name[i++]=buff[j++];
	}
	r.name[i]='\0';
	i=0;
	j++;
	while(buff[j]!='|')
	{
		r.artist[i++]=buff[j++];
	}
	r.artist[i]='\0';
	i=0;
	j++;
		while(buff[j]!='|')
	{
		r.genre[i++]=buff[j++];
	}
	r.genre[i]='\0';
	i=0;
	j++;
	while(buff[j]!='|')
	{
		r.album[i++]=buff[j++];
	}
	r.album[i]='\0';
	i=0;
	j++;
	while(buff[j]!='|')
	{
		r.price[i++]=buff[j++];
	}
	r.price[i]='\0';
	i=0;
	j++;
	while(buff[j]!='|')
	{
		r.quantity[i++]=buff[j++];
	}
	r.quantity[i]='\0';
	i=0;
	j++;
	while(buff[j]!='|')
	{
		r.nosold[i++]=buff[j++];
	}
	r.nosold[i]='\0';
	return(r);
}
void store_data::CreateOrder()
{
    system("cls");
    fstream fp;
	char id[35],buff[60];
	char a[20]="XN";
	int i,j,n;
	record s[100];
	fp.open(fname,ios::in);
    if(fp.fail())
	{
		cout<<"\n\n\t\t==========================================="<<endl;
		cout<<"\t\t\t~~~ ERROR FILE!! ~~~\n\t\t\t~~~ PLEASE CHECK AGAIN!! ~~~"<<endl;
		cout<<"\t\t==========================================="<<endl;
		exit(0);
	}
	cout<<"\n\t\t\t:::::::::::::::::::::::::: CREATE ORDER :::::::::::::::::::::::::::::"<<endl;
	cout<<"---------------------------------------------------------------------------------------------------------------------"<<endl<<endl;
	cout<<"\n\t\t\t>>> ENTER THE MUSIC ID: ";
	cin>>id;
	i=0;
	while(1)
	{
		fp.getline(buff,60);
		if(fp.eof())break;
		s[i]=unpack(buff);
		i++;
	}
	for(j=0;j<i;j++)
	{
		if(strcmp(s[j].id,id)==0)
		{
			cout<<"\n\t\t\t=============================================="<<endl;
			cout<<"\t\t\t::::::::::::::::::.DETAILS.:::::::::::::::::::"<<endl;
			cout<<"\t\t\t=============================================="<<endl;
			cout<<"\t\t\t: *Music ID                :"<<s[j].id<<endl;
			cout<<"\t\t\t: *Music Name              :"<<s[j].name<<endl;
			cout<<"\t\t\t: *Price                   :"<<s[j].price<<endl;
			cout<<"\t\t\t: *Quantity                :"<<s[j].quantity<<endl;
			cout<<"\t\t\t: *Number of Sold Items    :"<<s[j].nosold<<endl;
			cout<<"\t\t\t=============================================="<<endl<<endl;	
			if(strcmp(s[j].quantity,a)==0)
			{
				cout<<"\n\t\t==============================================================="<<endl;
				cout<<"\t\t\t~~~~~ SORRY,NO ITEMS AVALIABLE. ~~~~~";
				cout<<"\t\t==============================================================="<<endl;
				return;
			}
			cout<<"\n\t\t\t==============================================================="<<endl;
			cout<<"\t\t\t:::::::::::::::::::::::.CREATING ORDER.::::::::::::::::::::::::"<<endl;
			cout<<"\t\t\t==============================================================="<<endl;
			cout<<"\t\t\t>>>> *Enter Quantity       :";
			cin>>n;cout<<endl;
			stringstream q(s[j].quantity);
			stringstream p(s[j].price);
			stringstream ns(s[j].nosold);
	        int qu=0,pr=0,sol=0;
	        q>>qu;
	        p>>pr;
	        ns>>sol;
	        if(n>0&&n<=qu)
	        {
	        	if(strcmp(s[j].nosold,a)==0)
				{
					sol=0;
				}
	        	pr=pr*n;
				qu=qu-n;
				sol=sol+n;
			    cout<<"\t\t\t>>>> *Price             :Rs. "<<pr<<endl;
			    cout<<"\t\t\t===============================================================\n"<<endl;
				ostringstream nosold1;
				ostringstream quantity1;
				quantity1<<qu;
				nosold1<<sol;
				string quanti=quantity1.str();
				string noso=nosold1.str();	
				char ab[50],cd[50];
			    quanti.copy(ab,quanti.size()+1);
				noso.copy(cd,noso.size()+1);		
				strcpy(s[j].quantity,ab);
				strcpy(s[j].nosold,cd);
				char cname[50],cphno[50],cadd[50];
			cout<<"\n\t\t\t>>> Enter Customer\'s Name         :";
			cin>>cname;
			cout<<"\t\t\t>>> Enter Customer\'s Phone Number :";
			cin>>cphno;
			cout<<"\t\t\t>>> Enter Customer\'s Address      :";
			cin>>cadd;
    		cout<<"\n\t\t\t========================================================================================"<<endl;
    		cout<<"\t\t\t:::::::::::::::::::::::::::::.VH1   MUSIC   STORE.::::::::::::::::::::::::::::::::::::::"<<endl;
    		cout<<"\t\t\t:::::::::::::::::::::::::::::::.BILLING RECEIPT.::::::::::::::::::::::::::::::::::::::::"<<endl;
    		cout<<"\t\t\t========================================================================================"<<endl;
    		cout<<"\t\t\t:.Customer\'s Name :"<<cname<<setw(40)<<"Phone Number:"<<cphno<<endl;
    		cout<<"\t\t\t:.\t\t\tAddress :"<<cadd<<endl;
    		cout<<"\t\t\t----------------------------------------------------------------------------------------"<<endl;
    		cout<<"\t\t\t Music Name"<<setw(25)<<"Quantity"<<setw(25)<<" Price \(in Rs.\) "<<setw(25)<<"Total Price\(in Rs.\)"<<endl;
    		cout<<"\t\t\t----------------------------------------------------------------------------------------"<<endl;
    		cout<<"\t\t\t"<<s[j].name<<setw(25)<<n<<setw(25)<<s[j].price<<setw(25)<<pr<<endl;
    		cout<<"\t\t\t========================================================================================"<<endl;	
		}
		else
			{
				cout<<"\n\n\t\t=================================================="<<endl;
				cout<<"\t\t\t*** ORDER CAN\'T BE PLACED DUE TO WRONG INPUT ***"<<endl;
				cout<<"\t\t=================================================="<<endl;
				break;
			}
		break;
		}
	}
	if(j==i)
	{
		cout<<"\n\n\t\t\t==========================================="<<endl;
   		cout<<"\t\t\t       ~~~~ RECORD NOT FOUND!! ~~~~"<<endl;
   		cout<<"\t\t\t==========================================="<<endl;
		return;
	}
	fp.close();
	fstream fd;
	fd.open(fname,ios::out|ios::trunc);
	if(fd.fail())
	
	{
		cout<<"\n\n\t\t==========================================="<<endl;
		cout<<"\t\t\t~~~ ERROR FILE!! ~~~\n\t\t\t~~~ PLEASE CHECK AGAIN!! ~~~"<<endl;
		cout<<"\t\t==========================================="<<endl;
		exit(0);
	}
	for(j=0;j<i;j++)
	{
		pack(s[j]);
	}
	cout<<"\n\t\t\t========================================================"<<endl;
	cout<<"\n\t\t\t\t***** ORDER CREATED SUCCESSFUL *****"<<endl<<endl;
	cout<<"\t\t\t========================================================"<<endl;
	fd.close();
}
void store_data::FindMusic()
{
	system("cls");
	fstream fp;
	char id[50],buff[60];
	int i,j;
	record s;
	fp.open(fname,ios::in);
	if(fp.fail())
	{
		cout<<"\n\n\t\t==========================================="<<endl;
      cout<<"\t\t\t~~~ ERROR FILE!! ~~~\n\t\t\t~~~ PLEASE CHECK AGAIN!! ~~~";
      cout<<"\t\t==========================================="<<endl;
	  exit(0);
	}
    int ch;
    cout<<"\n\t\t::::::::::::::::::::::::::.FIND MUSIC.:::::::::::::::::::::::::::::"<<endl<<endl;
    cout<<"--------------------------------------------------------------------------------------------------------------"<<endl<<endl;
    cout<<"\n\t\t\t============================================"<<endl;
    cout<<"\t\t\t:::::::::::::.SEARCH BASED ON.::::::::::::::"<<endl;
    cout<<"\t\t\t============================================"<<endl;
    cout<<"\t\t\t::             1.Music ID                 ::"<<endl;
    cout<<"\t\t\t::             2.Music Name               ::"<<endl;
    cout<<"\t\t\t::             3.Album Name               ::"<<endl;
    cout<<"\t\t\t::             4.Artist Name              ::"<<endl;
    cout<<"\t\t\t============================================"<<endl;
    cout<<"\t\t\t>>> Enter your choice of Search: ";
    cin>>ch;
    cout<<"\t\t\t--------------------------------------------"<<endl<<endl;
    switch(ch)
    {
  	 case 1:
  		cout<<"\n\t\t\t>>> ENTER THE MUSIC ID TO BE SEARCHED: ";
	    cin>>id;
	    i=0;
	    while(1)
	    {
	    fp.getline(buff,60);
		if(fp.eof())break;
		s=unpack(buff);
		if(strcmp(s.id,id)==0)
		{
			   cout<<"\n\t\t\t==========================================="<<endl;
			   cout<<"\t\t\t          *** RECORD FOUND! ***"<<endl;
			   cout<<"\t\t\t==========================================="<<endl;
		       cout<<"\t\t\t:::  * Music ID      :"<<s.id<<endl;
		       cout<<"\t\t\t:::  * Music Name    :"<<s.name<<endl;
		       cout<<"\t\t\t:::  * Artist\'s Name :"<<s.artist<<endl;
		       cout<<"\t\t\t:::  * Music Genre   :"<<s.genre<<endl;
		       cout<<"\t\t\t:::  * Album\'s Name  :"<<s.album<<endl;
		       cout<<"\t\t\t:::  * Price         :Rs."<<s.price<<endl;
		       cout<<"\t\t\t==========================================="<<endl;
			   return;
	   } 
   }
   cout<<"\n\n\t\t\t==========================================="<<endl;
   cout<<"\t\t\t       ~~~~ RECORD NOT FOUND!! ~~~~"<<endl;
   cout<<"\t\t\t==========================================="<<endl;
   return;
        break;
  	case 2:
  		cout<<"\n\t\t\t>>>ENTER THE MUSIC NAME TO BE SEARCHED:";
	    cin>>id;
	    i=0;
	    while(1)
	    {
	    fp.getline(buff,60);
		if(fp.eof())break;
		s=unpack(buff);
		if(strcmp(s.name,id)==0)
		{
			   cout<<"\n\t\t\t==========================================="<<endl;
			   cout<<"\t\t\t          *** RECORD FOUND! ***"<<endl;
			   cout<<"\t\t\t==========================================="<<endl;
		       cout<<"\t\t\t:::  * Music ID      :"<<s.id<<endl;
		       cout<<"\t\t\t:::  * Music Name    :"<<s.name<<endl;
		       cout<<"\t\t\t:::  * Artist\'s Name :"<<s.artist<<endl;
		       cout<<"\t\t\t:::  * Music Genre   :"<<s.genre<<endl;
		       cout<<"\t\t\t:::  * Album\'s Name  :"<<s.album<<endl;
		       cout<<"\t\t\t:::  * Price         :Rs."<<s.price<<endl;
		       cout<<"\t\t\t==========================================="<<endl;
			   return;
	   } 
   }
   cout<<"\n\n\t\t\t==========================================="<<endl;
   cout<<"\t\t\t       ~~~~ RECORD NOT FOUND!! ~~~~"<<endl;
   cout<<"\t\t\t==========================================="<<endl;
   return;
  		break;
  	case 3:
  	    cout<<"\n\t\t\t>>> ENTER THE ALBUM NAME TO BE SEARCHED:";
  	      cin>>id;
	    i=0;
	    while(1)
	    {
	    fp.getline(buff,60);
		if(fp.eof())break;
		s=unpack(buff);
		if(strcmp(s.album,id)==0)
		{
			   cout<<"\n\t\t\t==========================================="<<endl;
			   cout<<"\t\t\t         *** RECORD FOUND! ***"<<endl;
			   cout<<"\t\t\t==========================================="<<endl;
		       cout<<"\t\t\t:::  * Music ID      :"<<s.id<<endl;
		       cout<<"\t\t\t:::  * Music Name    :"<<s.name<<endl;
		       cout<<"\t\t\t:::  * Artist\'s Name :"<<s.artist<<endl;
		       cout<<"\t\t\t:::  * Music Genre   :"<<s.genre<<endl;
		       cout<<"\t\t\t:::  * Album\'s Name  :"<<s.album<<endl;
		       cout<<"\t\t\t:::  * Price         :Rs."<<s.price<<endl;
		       cout<<"\t\t\t==========================================="<<endl;
			   return;
	   } 
   }
   cout<<"\n\n\t\t\t==========================================="<<endl;
   cout<<"\t\t\t       ~~~~ RECORD NOT FOUND!! ~~~~"<<endl;
   cout<<"\t\t\t==========================================="<<endl;
   return;
  		break;
  	case 4:
  	    cout<<"\n\t\t\t>>> ENTER THE MUSIC ARTIST TO BE SEARCHED:";
	    cin>>id;
	    i=0;
	    while(1)
	    {
	    fp.getline(buff,60);
		if(fp.eof())break;
		s=unpack(buff);
		if(strcmp(s.artist,id)==0)
		{
			   cout<<"\n\t\t\t==========================================="<<endl;
			   cout<<"\t\t\t         *** RECORD FOUND! ***"<<endl;
			   cout<<"\t\t\t==========================================="<<endl;
		       cout<<"\t\t\t:::  * Music ID      :"<<s.id<<endl;
		       cout<<"\t\t\t:::  * Music Name    :"<<s.name<<endl;
		       cout<<"\t\t\t:::  * Artist\'s Name :"<<s.artist<<endl;
		       cout<<"\t\t\t:::  * Music Genre   :"<<s.genre<<endl;
		       cout<<"\t\t\t:::  * Album\'s Name  :"<<s.album<<endl;
		       cout<<"\t\t\t:::  * Price         :Rs."<<s.price<<endl;
		       cout<<"\t\t\t==========================================="<<endl;
			   return;
	   } 
   }
    cout<<"\n\n\t\t\t==========================================="<<endl;
    cout<<"\t\t\t     ~~~~ RECORD NOT FOUND!! ~~~~"<<endl;
    cout<<"\t\t\t==========================================="<<endl;
    return;
    break;
  	default:
  		cout<<"\n\n\t\t\t============================================"<<endl;
  		cout<<"\t\t\t ~~~ YOU HAVE ENTERED INCORRECT INPUT!! ~~~"<<endl;
  		cout<<"\t\t\t============================================"<<endl;
  		
	  }	
}
void store_data::SoldItems()
{
    system("cls");
    fstream fp;
	char buff[60];
	char a[5]="NA";
	record r;
	fp.open(fname,ios::in);
	if(fp.fail())
	{
		cout<<"\t\t==========================================="<<endl;
		cout<<"\n\t\t\t~~~ ERROR FILE!! ~~~\n\t\t\t~~~ PLEASE CHECK AGAIN!! ~~~";
		cout<<"\t\t==========================================="<<endl;
		exit(0);
	}
	cout<<"\n\n\n";
    cout<<"\n\t\t::::::::::::::::::::::::::.SOLD MUSIC ITEMS RECORD.:::::::::::::::::::::::::::::"<<endl<<endl;
    cout<<"---------------------------------------------------------------------------------------------------------------------"<<endl<<endl;
    
	for(int i=1;i<49;i++)
	{
	  cout<<"==";
    }
	cout<<"\n";
    cout<<setw(15)<<"Music ID"<<setw(20)<<"Music Name"<<setw(15)<<"Price"<<setw(15)<<"Quantity"<<setw(15)<<"     Number of Sold Items\n";
    for(int i=1;i<49;i++)
	{
	  cout<<"==";
    }
	cout<<"\n";
	while(1)
	{
		fp.getline(buff,60);
		if(fp.eof())break;
		r=unpack(buff);
		if((strcmp(r.nosold,a))!=0)
		{
		  cout<<setw(15)<<r.id<<setw(20)<<r.name<<setw(15)<<r.price<<setw(15)<<r.quantity<<setw(15)<<r.nosold<<endl;
	    }
	}
	for(int i=1;i<49;i++)
	{
	  cout<<"==";
    }
	cout<<"\n\n";
	fp.close();
	return;
}
void store_data::ItemStock()
{
    system("cls");
    fstream fp;
	char buff[60];
	record r;
	char a[5]="NA";
	fp.open(fname,ios::in);
	if(fp.fail())
	{
		cout<<"\n\n\t\t==========================================="<<endl;
		cout<<"\t\t\t~~~ ERROR FILE!! ~~~\n\t\t\t~~~ PLEASE CHECK AGAIN!! ~~~"<<endl;
		cout<<"\t\t==========================================="<<endl;
		exit(0);
	}
	cout<<"\n\n\n";
    cout<<"\n\t\t::::::::::::::::::::::::::.MUSIC ITEM STOCK RECORDS.:::::::::::::::::::::::::::::"<<endl<<endl;
    cout<<"---------------------------------------------------------------------------------------------------------------------"<<endl<<endl;
	for(int i=1;i<50;i++)
	{
	  cout<<"==";
    }
	cout<<"\n";
    cout<<setw(15)<<"Music ID"<<setw(15)<<"Music Name"<<setw(15)<<"Price"<<setw(15)<<"Quantity"<<setw(15)<<"     Number of Sold Items\n";
    for(int i=1;i<50;i++)
	{
	  cout<<"==";
    }
	cout<<"\n";
	while(1)
	{
		fp.getline(buff,60);
		if(fp.eof())break;
		r=unpack(buff);
		if(strcmp(r.quantity,a)!=0)
		{
		cout<<setw(15)<<r.id<<setw(15)<<r.name<<setw(15)<<r.price<<setw(15)<<r.quantity<<setw(15)<<r.nosold<<endl;
	}
	}
	 for(int i=1;i<50;i++)
	{
	  cout<<"==";
    }
	cout<<"\n\n";
	fp.close();
	return;
}
void store_data::AllItems()
{
	system("cls");
    fstream fp;
	char buff[45];
	record r;
	fp.open(fname,ios::in);
	if(fp.fail())
	{
		cout<<"\n\n\t\t==========================================="<<endl;
		cout<<"\t\t\t~~~ ERROR FILE!! ~~~\n\t\t\t~~~ PLEASE CHECK AGAIN!! ~~~"<<endl;
		cout<<"\t\t==========================================="<<endl;
		exit(0);
	}
	cout<<"\n\n\n";
    cout<<"\n\t\t::::::::::::::::::::::::::.VH1 MUSIC RECORDS.:::::::::::::::::::::::::::::"<<endl<<endl;
    cout<<"-------------------------------------------------------------------------------------------------------------------------"<<endl<<endl;
	for(int i=1;i<60;i++)
	{
	  cout<<"==";
    }
	cout<<"\n";
    cout<<setw(15)<<"Music ID"<<setw(25)<<"Music Name"<<setw(25)<<"Artist Name "<<setw(15)<<"Genre "<<setw(15)<<"Album Name "<<setw(15)<<"Price\n";
   for(int i=1;i<60;i++)
	{
	  cout<<"==";
    }
	cout<<"\n";
	while(1)
	{
		fp.getline(buff,60);
		if(fp.eof())break;
		r=unpack(buff);
		cout<<setw(15)<<r.id<<setw(25)<<r.name<<setw(25)<<r.artist<<setw(15)<<r.genre<<setw(15)<<r.album<<setw(15)<<r.price<<endl;
	}
	 for(int i=1;i<60;i++)
	{
	  cout<<"==";
    }
	cout<<"\n\n";
	fp.close();
	return;
}
void store_data::AddNewItem()
{
    system("cls");
  	record r;
	cout<<"\n\t\t::::::::::::::::::::::::::.ADD NEW RECORD.:::::::::::::::::::::::::::::"<<endl;
    cout<<"--------------------------------------------------------------------------------------------------------------\n";
  	cout<<"\n\t\t\t==============================================="<<endl;
  	cout<<"\t\t\t::::::::::::.Enter the Details.:::::::::::::"<<endl;
  	cout<<"\t\t\t==============================================="<<endl;
	cout<<"\t\t\t>>> ENTER MUSIC ID:";
	cin>>r.id;cout<<endl;
	cout<<"\t\t\t>>> ENTER MUSIC NAME:";
	cin>>r.name;cout<<endl;
	cout<<"\t\t\t>>> ENTER ARTIST\'s NAME:";
	cin>>r.artist;cout<<endl;
	cout<<"\t\t\t>>> ENTER MUSIC GENRE:";
	cin>>r.genre;cout<<endl;
	cout<<"\t\t\t>>> ENTER MUSIC ALBUM NAME:";
	cin>>r.album;cout<<endl;
	cout<<"\t\t\t>>> ENTER PRICE FOR EACH PIECE:";
	cin>>r.price;cout<<endl;
	cout<<"\t\t\t>>> ENTER NO OF QUANTITY:";
	cin>>r.quantity;cout<<endl;
	strcpy(r.nosold,"NA");
	cout<<"\t\t\t==============================================="<<endl;
	pack(r);
}
void store_data::EditItem()
{
	system("cls");
    fstream fp;
	char id[35],buff[60],id1[50],name[50],genre[50],art[50],album[50],price[50],quan[50];
	char a[5]="XN";
	int i,j;
	record s[100];
	fp.open(fname,ios::in);
    if(fp.fail())
	{
		cout<<"\n\n\t\t==========================================="<<endl;
		cout<<"\t\t\t~~~ ERROR FILE!! ~~~\n\t\t\t~~ PLEASE CHECK AGAIN!! ***"<<endl;
		cout<<"\t\t==========================================="<<endl;
		exit(0);
	}
	 cout<<"\n\t\t:::::::::::::::::::::::::: EDIT RECORD :::::::::::::::::::::::::::::"<<endl;
    cout<<"------------------------------------------------------------------------------------------------------------------"<<endl<<endl;
    
	cout<<"\n\t\t\t>>> ENTER THE MUSIC ID TO BE MODIFIED: ";
	cin>>id;cout<<endl;
	i=0;
	while(1)
	{
		fp.getline(buff,60);
		if(fp.eof())break;
		s[i]=unpack(buff);
		i++;
	}
	for(j=0;j<i;j++)
	{
		if(strcmp(s[j].id,id)==0)
		{
			cout<<"\n\t\t\t============================================"<<endl;
			cout<<"\t\t\t::::::::::::::::.DETAILS.:::::::::::::::::::"<<endl;
			cout<<"\t\t\t============================================"<<endl;
			cout<<"\t\t\t::: * Music ID      :"<<s[j].id<<endl;
			cout<<"\t\t\t::: * Music Name    :"<<s[j].name<<endl;
			cout<<"\t\t\t::: * Artist\'s Name :"<<s[j].artist<<endl;
			cout<<"\t\t\t::: * Genre         :"<<s[j].genre<<endl;
			cout<<"\t\t\t::: * Album Name    :"<<s[j].album<<endl;
			cout<<"\t\t\t::: * Price         :"<<s[j].price<<endl;
			cout<<"\t\t\t::: * Quantity      :"<<s[j].quantity<<endl;
			cout<<"\t\t\t============================================"<<endl;
			cout<<"\n\n\t\t\t=============================================================="<<endl;
			cout<<"\t\t\t:::::::::::::::::::::.ENTER THE NEW VALUES.::::::::::::::::::"<<endl;
			cout<<"\t\t\t=============================================================="<<endl;
            cout<<"\t\t\t>>> Enter Music ID (XN FOR NO CHANGE)       :";
			cin>>id1;cout<<endl;
			cout<<"\t\t\t>>> Enter Music Name (XN FOR NO CHANGE)     :";
		    cin>>name;cout<<endl;
			cout<<"\t\t\t>>> Enter Artist\'s Name (XN FOR NO CHANGE)  :";
			cin>>art;cout<<endl;
			cout<<"\t\t\t>>> Enter Genre (XN FOR NO CHANGE)          :";
			cin>>genre;cout<<endl;
			cout<<"\t\t\t>>> Enter Album Name (XN FOR NO CHANGE)     :";
			cin>>album;cout<<endl;
			cout<<"\t\t\t>>> Enter Price (XN FOR NO CHANGE)          :";
			cin>>price;cout<<endl;
			cout<<"\t\t\t>>> Enter Quantity (XN FOR NO CHANGE)       :";
			cin>>quan;cout<<endl;
			cout<<"\t\t\t=============================================================="<<endl;
			if((strcmp(id1,a))!=0)
			    strcpy(s[j].id,id1);
			if((strcmp(name,a))!=0)
			    strcpy(s[j].name,name);
			if((strcmp(art,a))!=0)
			    strcpy(s[j].artist,art); 
			if((strcmp(genre,a))!=0)
			    strcpy(s[j].genre,genre);
			if((strcmp(quan,a))!=0)
			    strcpy(s[j].quantity,quan);
			if((strcmp(album,a))!=0)
			    strcpy(s[j].album,album);   
			if((strcmp(price,a))!=0)
			    strcpy(s[j].price,price);
			break;
		}
	}
	if(j==i)
	{
		cout<<"\n\n\t\t\t==========================================="<<endl;
        cout<<"\t\t\t       ~~~~~ RECORD NOT FOUND!! ~~~~"<<endl;
   		cout<<"\t\t\t==========================================="<<endl;
		return;
	}
	fp.close();
	fstream fd;
	fd.open(fname,ios::out|ios::trunc);
	if(fd.fail())
	
	{
		cout<<"\n\n\t\t==========================================="<<endl;
		cout<<"\t\t\t~~~ ERROR FILE!! ~~~\n\t\t\t~~~ PLEASE CHECK AGAIN!! ~~~"<<endl;
		cout<<"\t\t==========================================="<<endl;
		exit(0);
	}
	for(j=0;j<i;j++)
	{
		pack(s[j]);
	}
	cout<<"\n\t\t\t=========================================================="<<endl;
	cout<<"\t\t\t\t*********** RECORD MODIFICATION SUCCESSFUL *********"<<endl<<endl;
	cout<<"\n\t\t\t=========================================================="<<endl;
	fd.close();
}
void store_data::RemoveItem()
{
	ifstream is(fname);
	ofstream ofs;
	char id[30];
	ofs.open("temp.txt",ios::out);
	char c;
	int n=1;
	int line_no=1;
	fstream fp;
	char buff[45];
	int h=1;
	record r;
	fp.open(fname,ios::in);
	if(fp.fail())
	{
		cout<<"\n\n\t\t==========================================="<<endl;
		cout<<"\t\t\t~~~ ERROR FILE!! ~~~\n\t\t\t~~~ PLEASE CHECK AGAIN!! ~~~"<<endl;
		cout<<"\t\t==========================================="<<endl;
		exit(0);
	}
	 cout<<"\n\t\t::::::::::::::::::::::::::.DELETE MUSIC RECORD.:::::::::::::::::::::::::::::"<<endl;
    cout<<"---------------------------------------------------------------------------------------------------------------------";
	cout<<endl<<endl;
    cout<<setw(55)<<"*** VH1 MUSIC STORE DETAILS ***\n";
	for(int i=1;i<60;i++)
	{
	  cout<<"==";
    }
	cout<<"\n";
    cout<<setw(15)<<"Music Index"<<setw(25)<<"Music Name"<<setw(25)<<"Artist Name "<<setw(15)<<"Genre "<<setw(15)<<"Album Name "<<setw(15)<<"Price\n";
   for(int i=1;i<60;i++)
	{
	  cout<<"==";
    }
	cout<<"\n";
	while(1)
	{
		fp.getline(buff,60);
		if(fp.eof())break;
		r=unpack(buff);
		cout<<setw(15)<<h++<<setw(25)<<r.name<<setw(15)<<r.artist<<setw(25)<<r.genre<<setw(15)<<r.album<<setw(15)<<r.price<<endl;
	}
	 for(int i=1;i<60;i++)
	{
	  cout<<"==";
    }
	cout<<"\n\n";
	fp.close();
	cout<<endl<<endl;
	cout<<"\t\t\t>>> ENTER THE MUSIC INDEX TO BE REMOVED:";
    cin>>n;
	while(is.get(c))
	{
		if(c=='\n')
		  line_no++;
	      if(line_no!=n)
		   ofs<<c;
    }
    cout<<"\n\t\t\t======================================================="<<endl;
	cout<<"\t\t\t\t***** RECORD DELETED SUCCESSFULLY *****"<<endl<<endl;
	cout<<"\t\t\t======================================================="<<endl;
	ofs.close();
	is.close();
	remove(fname);
	rename("temp.txt",fname);
}


int main()
{ 
    int choice;
    store_data A;
    
    cout<<"\n\tWELCOME TO.."<<endl;
	cout<<"\t\t            _  _    _ ___ __   _ ___ _  _  _"<<endl;
	cout<<"\t\t\\  /|_| /|  |\\/|| |(_  | |    (_  | | ||_)|_"<<endl;
	cout<<"\t\t \\/ | |  |  |  ||_| _)_|_|__   _) | |_|| \\|_"<<endl;
    while(true)
    {
    cout<<"\n\t\t\t==============================="<<endl;
    cout<<"\t\t\t::::.Music Store Main Menu.::::"<<endl;
    cout<<"\t\t\t==============================="<<endl;
    cout<<"\t\t\t||     1.Create Order        ||"<<endl;
    cout<<"\t\t\t||     2.Find Music          ||"<<endl;
    cout<<"\t\t\t||     3.Sold Items          ||"<<endl;
    cout<<"\t\t\t||     4.Items in Stock      ||"<<endl;
    cout<<"\t\t\t||     5.All Items           ||"<<endl;
    cout<<"\t\t\t||     6.Add New Items       ||"<<endl;
    cout<<"\t\t\t||     7.Edit Item           ||"<<endl;
    cout<<"\t\t\t||     8.Remove Item         ||"<<endl;
    cout<<"\t\t\t||     9.Exit                ||"<<endl;
    cout<<"\t\t\t==============================="<<endl;
	cout<<"\t\t\t::Enter the choice: ";
	cin>>choice;
	cout<<"\t\t\t-------------------------\n";
	switch(choice)
	{
		case 1:
			A.CreateOrder();
			break;
		case 2:
			A.FindMusic();
			break;
		case 3:
			A.SoldItems();
			break;
		case 4:
			A.ItemStock();
			break;
		case 5:
			A.AllItems();
			break;
		case 6:
			A.AddNewItem();
			break;
		case 7:
			A.EditItem();
			break;
		case 8:
			A.RemoveItem();
			break;
		case 9:
			char a;
			cout<<"\n\t\t\t============================"<<endl;
			cout<<"\t\t\t:::.Are you sure?(Y/N): ";
			cin>>a;
			cout<<"\t\t\t============================"<<endl;
			if(a=='Y'||a=='y')
			{
			exit(0);	
			}
			break;
		default:
			cout<<"\n\n\t\t==========================================="<<endl;
		    cout<<"\t\t    *** PLEASE ENTER CORRECT INPUT ***"<<endl;
			cout<<"\t\t==========================================="<<endl;
			
	}
}
}


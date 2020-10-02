//To Compile Decision_Making_Bash_Script.cpp g++ -I/usr/include/cppconn -o dmbs Decision_Making_Bash_Script.cpp -L/usr/lib -lmysqlcppconn -ljsoncpp 
//And to Run ./dmbs
//You need the json lib , mysql_connector lib to compile the file


#include<iostream>
#include<vector>
#include<string>
#include<mysql_connection.h>
#include<cppconn/resultset.h>
#include<cppconn/driver.h>
#include<fstream>
#include<sstream>
#include<jsoncpp/json/json.h>
#include<cppconn/connection.h>
#include<cppconn/statement.h>
#include<cppconn/exception.h>
#include<unordered_set>

#define Infi 1000000000
using namespace std;
using namespace sql;
using namespace Json;


int main(int argc,char* argv[]){
	//Reading Database Credential from JSON File
	Reader cr;
        Value cob;
        ifstream cifs("credential.json");
        cr.parse(cifs,cob);
        const string url=cob["url"].asString();
        const string user=cob["username"].asString();
        const string password=cob["password"].asString();
        const string database=cob["database"].asString();
	try{
		//Connecting To Database
		Driver& driver = *get_driver_instance();
                Connection& con = *driver.connect(url,user,password);
                con.setSchema(database);
                Statement& stmt=*con.createStatement();

		//Getting Size of Graph
		ResultSet& size=*stmt.executeQuery("SELECT count(*) FROM City_master");
		int n;
		if(size.next()){
			n=size.getInt(1);
		}

		//Fetching City Id and City Name
		ResultSet& rs=*stmt.executeQuery("SELECT * FROM City_master");
		cout<<"City Id     City Name"<<endl;
                while(rs.next()){
                        cout<<"  "<<rs.getInt(1)<<"           "<<rs.getString(2)<<endl;
                }

		//Getting Id's From User
		int id1,id2;
		a:
		cout<<"Enter City Id of Source"<<"(1 to "<<n<<") :";
		cin>>id1;
		if(id1 > n){
			cout<<"City Id "<<id1<<" not Found!"<<endl;
			cout<<"WRONG CITY ID ! Enter it Again !"<<endl;
			goto a;
		}
		b:
		cout<<"Enter City Id of Destination<<"<<"(1 to "<<n<<") :";
		cin>>id2;
		if(id2>n){
			cout<<"City Id "<<id2<<" not Found!"<<endl;
			cout<<"WRONG CITY ID ! Enter it Again !"<<endl;
			goto b;
		}

		//Populating City
		int a,b,c,city_data[8][8];
		populate(city_data,n+1);

		vector<City*>v;
		for(int i=0;i<n+1;i++){
			City* a0=new City(i);
			v.push_back(a0);
		}

		//Getting Fare list and Storing into City_data
		ResultSet& rs1=*stmt.executeQuery("SELECT * FROM farelist");
		while(rs1.next()){
			a=rs1.getInt(1);
			b=rs1.getInt(2);
			c=rs1.getInt(3);
			city_data[a][b]=c;
			if(city_data[a][b]>0){
				v[a]->add_Neighbour(b,c);
			}
		}

		//Displaying Min Fare
		vector<int>pt(v.size());
		int fare=minFare(v,id1,id2,pt);
		if(fare!=Infi && fare!=0)
			cout<<"Min Fare From "<<id1<<" to "<<id2<<" is : "<<fare<<endl;
		else
			cout<<"No Path Found for "<<id1<<" to "<<id2<<endl;

		}catch(SQLException& e){
		cout<<"Error! "<<e.what()<<endl;
	}
	return 0;
}

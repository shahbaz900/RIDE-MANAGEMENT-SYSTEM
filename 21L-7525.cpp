#include<iostream>
#include<fstream>
#include<string>
using namespace std;
class name
{
private:
	char* fname;
	char* lname;
public:
	name();
	name(char *, char *);
	virtual void setdata();
	virtual void setdata011();
	virtual void getdata();
	friend ostream& operator<<(ostream& out, const name& n)
	{
		out << n.fname;
		out << " " << n.lname << endl;
		return out;
	}
};
name::name() 
{
	fname = new char[20];
	lname = new char[20];
}
name::name(char* a, char* b)
{
	fname = a;
	lname = b;
}
void name::getdata() 
{
	cout << "The name of customer:" << fname << " " << lname << endl;
}
void name::setdata()
{
	ofstream file1("customer.txt",ios::app);
	cout << "enter first name:";
	cin >> fname;
	cout << "enter last name:";
	cin >> lname;
	file1 << fname << "," << lname<<",";
}
void name::setdata011()
{
	ofstream file2("driver.txt", ios::app);
	cout << "enter first name:";
	cin >> fname;
	cout << "enter last name:";
	cin >> lname;
	file2 << fname << "," << lname << ",";
}
class date
{
	int day; int month; int year;
public:
	date(int = 0, int = 0, int = 0);
	void setdata1();
	void setdata11();
	void setdata125();
	void getdata1();

	friend ostream& operator<<(ostream& out, const date& obj)
	{
		out << obj.day;
		out << obj.month << " " << obj.year << ".";
	}
};
date::date(int a, int b, int c)
{
	day = a;
	month = b;
	year = c;
}
void date::getdata1() {
	cout << "date:"<<day << "/" << month << "/" << year << endl;
}
void date::setdata1()
{
	cout << endl << "enter date of birth:" << endl;
	ofstream file1("customer.txt",ios::app);
	cout << "enter day:";
	cin >> day;
	cout << "enter month:";
	cin >> month;
	cout << "enter year:";
	cin >> year;
	file1 << day <<","<< month<<","<< year<<",";
}
void date::setdata125()
{
	cout << endl << "enter date of birth:" << endl;
	ofstream file2("service.txt", ios::app);
	cout << "enter day:";
	cin >> day;
	cout << "enter month:";
	cin >> month;
	cout << "enter year:";
	cin >> year;
	file2 << day << "," << month << "," << year << ",";
}
void date::setdata11()
{
	
	ofstream file2("driver.txt", ios::app);
	cout << "enter day:";
	cin >> day;
	cout << "enter month:";
	cin >> month;
	cout << "enter year:";
	cin >> year;
	file2 << day << "," << month << "," << year << ",";
}
class mtime
{
	int hour; int min; int sec;
public:
	mtime();
	void getdata();
	void setdata();
	void setdata1225();
	void setdata01();
};
mtime::mtime()
{
	hour = 0;
	min = 0;
	sec = 0;
}
void mtime::setdata() {
	ofstream file2("driver.txt", ios::app);
	cout << "enter hour:";
	cin >> hour;
	cout << "enter min:";
	cin >> min;
	cout << "enter sec:";
	cin >> sec;
	file2 << hour <<","<< min <<","<< sec << ",";
}
void mtime::setdata1225() {
	ofstream file2("service.txt", ios::app);
	cout << "enter hour:";
	cin >> hour;
	cout << "enter min:";
	cin >> min;
	cout << "enter sec:";
	cin >> sec;
	file2 << hour << "," << min << "," << sec << ",";
}
void mtime::setdata01() {
	
	cout << "enter hour:";
	cin >> hour;
	cout << "enter min:";
	cin >> min;
	cout << "enter sec:";
	cin >> sec;
}
void mtime::getdata()
{
	cout << "hour:" << hour << endl;
	cout << "min:" << min << endl;
	cout << "sec:" << sec << endl;
}
class service
{
	char* source;
	char* destination;
	float distance;
	date bookdate;
	mtime booktime;
	bool status;
	float fuelrate;
	int cid;
	int did;
	int vid;
public:
	service();
	/*service(char * , char *, float = 0, bool = 0, float = 0, int = 0, int = 0, int = 0);*/
	virtual void setdata2();
};
service::service() 
{
	source = new char[20];
	destination = new char[20];
	distance = 0;
	status = 0;
	fuelrate = 0;
	cid = 0;
	did = 0;
	vid = 0;
}
void service::setdata2() 
{
	ofstream file2("service.txt", ios::app);
	bookdate.setdata125();
	booktime.setdata1225();
	cout << "enter source:";
	cin >> source;
	cout << "enter destination:";
	cin >> destination;
	cout << "enter distance:";
	cin >> distance;
	cout << "enter status:";
	cin >> status;
	cout << "enter fuelrate:";
	cin >> fuelrate;
	cout << "enter customer id:";
	cin >> cid;
	cout << "enter driver id:";
	cin >> did;
	cout << "enter vid:";
	cin >> vid;
	file2 << source << "," << destination << "," << distance << "," <<status << "," << fuelrate << "," << cid << "," << did << "," << vid << "."<<endl;
}
class ride :public service
{
	int noofpassengers;
	char* ridetype;
	float driverranking;
	float vehicleranking;
public:
	ride();
	void setdata2();
};
ride::ride()
{
	service();
	noofpassengers = 0;
	ridetype = new char[20];
	driverranking = 0;
	vehicleranking = 0;
}
void ride::setdata2() {
	cout << "write noofpassengers:";
	cin >> noofpassengers;
	cout << "write ridetype:";
	cin >> ridetype;
	cout << "write driverranking:";
	cin >> driverranking;
	cout << "write vehicle ranking:";
	cin >> vehicleranking;
}
class delivery :public service {
	float goodsweight;
	char* goodstype;
public:
	delivery();
	//delivery(float, char*);
	void setdata2();
};
delivery::delivery() {
	goodsweight = 0;
	goodstype = new char[20];
}
void delivery::setdata2()
{
	cout << "enter weight for delivery:";
	cin >> goodsweight;
	cout << "enter type for delivery:";
	cin >> goodstype;
}

class person 
{
private:
	name pname;
	date dob;
	int cid;
	int age;
	int nid;
public:
	person(int = 0, int = 0);
	virtual void setdata3();
	void getdata4();
	virtual void setdata35();
};
person::person(int a, int b)
{
	pname;
	dob;
	age = a;
	nid = b;
}
void person::getdata4() 
{
	pname.getdata();
	dob.getdata1();
	cout << "age:" << age << " nid:" << nid << endl;
}
void person::setdata3() {
	ofstream file1("customer.txt",ios::app);
	cout << "enter customer id:";
	cin >> cid;
	file1 << cid << ",";
	pname.setdata();
	dob.setdata1();
	cout << "enter age:";
	cin >> age;
	cout << "enter national id:";
	cin >> nid;
	file1 << age << "," << nid << "." << endl;
}
void person::setdata35() {
	ofstream file2("driver.txt", ios::app);
	cout << "enter age:";
	cin >> age;
	cout << "enter national id:";
	cin >> nid;
	file2 << nid << "," << age << ",";
	pname.setdata011();
	dob.setdata11();
	
}
class customer :public person 
{
private:
	service** bookinghistory;
public:
	customer();
	void setdata5();
};
customer::customer() 
{
	bookinghistory = new service*[10];
	
}
void customer::setdata5() 
{
	ofstream file1("customer.txt", ios::app);
	setdata3();
}
class driver :public person
{
private:
	int did;
	char** licenselist;
	int nooflicences;
	float overllrank;
	float salary;
	int experience;
	int status;
	service** servicehistory;
public:
	driver();
	void setdata31();
};
driver::driver()
{
	did = 0;
	nooflicences = 0;
	overllrank = 0;
	salary=0;
	experience=0;
	status=0;
	servicehistory = new service*[10];
	licenselist = new char*[10];
}
void driver::setdata31() {
	ofstream file2("driver.txt", ios::app);
	cout << "enter driver id:";
	cin >> did;
	cout << "Enter no of licenses:";
	cin >> nooflicences;
	file2 <<endl<< did << "," << nooflicences << ".";
	setdata35();
}
class feature
{
	int fid;
	char* description;
	float cost;
public:
	feature(int = 0, float = 0);
};
feature::feature(int a, float b)
{
	description = new char[20];
	fid = a;
	cost = b;
}
class vehicle 
{
	int vid;
	int registrationno;
	float avgmileage;
	char* licencetype;
	bool status;
	char* fueltype;
	float overallranking;
	date manufacturingdate;
	feature* lidt;
	service** servicehistory;
public:
	vehicle();
	void setdata4();
	void getdata4();
};
vehicle::vehicle()
{
	vid = 0;
	registrationno = 0;
	avgmileage = 0;
	status = 0;
	fueltype = new char[20];
	licencetype = new char[20];
	lidt = new feature[10];
	servicehistory = new service*[10];
	lidt = new feature[10];
	overallranking = 0;
}
void vehicle::getdata4() {
	cout << "vehicle id:";
}
void vehicle::setdata4() {
	cout << "enter vehicle id:";
	cin >> vid;
	cout << "enter registration number:";
	cin >> registrationno;
	cout << "avg mileage:";
	cin >> avgmileage;
	cout << "enter status:";
	cin >> status;
	cout << "enter fueltype:";
	cin >> fueltype;
	cout << "overall ranking:";
	cin >> overallranking;
}
class tms 
{
public:
	tms(){};
	void addcustomer();
	void adddriver();
	void removedriver();
	void printcustomers();
	void printdriver();
	void printvehicle();
	void checkspec();
	void checkcustomer();
	void checkdriverranking();
	void addbonus();
	void requestservice();
	void setservice();
	void samevehicle();
	void samedriver();
	void pendingservice();
	void pendingdriver();
	void cancelservice();
	void completeservice();
	void checkdriver();
	void multiplelicense();
};
void tms::addcustomer()
{
	int a;
	customer* n1;
	n1 = new customer[15];
	cout << "enter amount of customer(s) you want to add:" ;
	cin >> a;
	for (int i = 0; i < a; i++)
	{
		n1[i].setdata5();
	}
}
void tms::adddriver()
{
	int a1;
	driver* d1;
	d1 = new driver[10];
	cout << "enter the amount of driver(s) you want to add:";
	cin >> a1;
	for (int i = 0; i < a1; i++)
	{d1[i].setdata31();}
}
void tms::removedriver()
{
	/*string line;
	int count = 0;
	string fname1, lname1="";
	int d, m, y, nid22, trash45;
	char trash22;
	cout << "enter the first name of the driver you want to delete:";
	cin >> fname1;
	fstream file4("driver.txt", ios::in);
	fstream file5("temp1122.txt", ios::out);
	while (!file4.eof())
	{
		file4 >> line;
		 {
			count = 0;
			if (fname1[0] == line[0])
			{
				for (int j = 0; j < fname1.length(); j++) 
				{
					if (fname1[j] == line[j]) 
					{
						count++;
						if (count >= 2) 
						{
							line.replace(0, line.length(), lname1, 0, 0);
							file5 << line << endl;
							break;
						}
					}
					else { break; }
				} 
					
			}
			if (count < 2) {
				file5 << line<<endl;
			}
			rename("driver.txt", "temp1122.txt");

		}
	}*/
	string deleteline="";
	string line;
	string fname;
	ifstream fin;
	fin.open("driver.txt");
	//ofstream fout;
	//fout.open("servicecancel.txt");
	ofstream temp;
	temp.open("temp1122.txt");
	cout << "enter  name of driver:";
	cin >> fname;
	
	while (getline(fin, line))
	{
		if (line[0] == fname[0] && line[1] == fname[1]) 
		{
			line.replace(line.find(fname), line.length(), "");
			temp<<line<<endl;
		}
		else
		{
			temp<<line<<endl;
		}
	}
	temp.close();
	fin.close();
	rename("driver.txt", "temp1122.txt");
	cout << "You can check deleted driver/updated data from file temp1122." << endl;
}
void tms::printcustomers() 
{
	string arr,arr1;
	int d,m,y,id,trash,nid1;
	char trash1;
	int i=0;
	fstream file4("customer.txt", ios::in);
	while (!file4.eof()) 
	{
		getline(file4, arr,',');
		getline(file4, arr1, ',');
		file4 >> d;
		file4 >> trash1;
		file4 >> m;
		file4 >> trash1;
		file4 >> y;
		file4 >> trash1;
		file4 >> id;
		file4 >> trash1;
		file4 >> trash;
		file4 >> trash1;
		file4 >> nid1;
		file4 >> trash1;
		cout << "driver-" << i << ":" << arr << " " << arr1 << endl;
		cout << "national id of the customer is:" << nid1 << " and " << "date of birth of customer is:" << d << "/" << m << "/" << y << endl;
		i++;
	}
}
void tms::printdriver() 
{
	int i = 0;
	string fname1, lname1;
	int d, m, y, nid22,trash45;
	char trash22;
	fstream file4("driver.txt", ios::in);
	while (!file4.eof()) 
	{
		getline(file4, fname1, ',');
		getline(file4, lname1, ',');
		/*file4 >> trash22;*/
		file4 >> d;
		file4 >> trash22;
		file4 >> m;
		file4 >> trash22;
		file4 >> y;
		file4 >> trash22;
		file4 >> nid22;
		file4 >> trash22;
		file4 >> trash45;
		file4 >> trash22;
		file4 >> trash45;
		file4 >> trash22;
		file4 >> trash45;
		file4 >> trash22;
		cout << "the name of driver-" << i + 1 << ":" << fname1 << " " << lname1 << endl;
		cout << "the national id of the customer is:" << nid22 << endl;
		cout << endl<<endl;
	}
}
void tms::printvehicle() {
	char t;
	int vid, rno,rdate,rmonth,ryear;
	string fuel, licence, feature;
	float avgmileage, rank,rate;
	bool stat,check;
	fstream file4("vehicle.txt", ios::in);
	while (!file4.eof())
	{
		file4 >> vid;
		file4 >> t;
		file4 >> rno;
		file4 >> t;
		file4 >> avgmileage;
		file4 >> t;
		getline(file4,licence,',');
		file4 >> stat;
		file4 >> t;
		getline(file4, fuel, ',');
		file4>>rank;
		file4 >> t;
		file4 >> rdate;
		file4 >> t;
		file4 >> rmonth;
		file4 >> t;
		file4 >> ryear;
		file4 >> t;
		file4 >>check ;
		file4 >> t;
		getline(file4, feature, ',');
		file4 >> rate;
		file4 >> t;
		cout << "your available vehicle is:" << vid << "with following features:"<<endl;
		cout << "the vehicle make model variant of:" << rdate << "/" << rmonth << "/" << ryear<<endl;
		cout << "The vehicle is " << feature<<endl;
		cout << "The rate of the vehicle per mile is:" << rate << endl;
		cout << "The vehicle runs on fuel type:" << fuel << " and is " << licence << " vehicle." << endl;
		cout << endl << endl;
	}
}
void tms::checkspec() 
{
	char t; int a;
	int vid, rno, rdate, rmonth, ryear;
	string fuel, licence, feature;
	float avgmileage, rank, rate;
	bool stat, check;
	cout << "enter the vehicle id for which you want to get details:";
	cin >> a;
	fstream file4("vehicle.txt", ios::in);
	while (!file4.eof()) 
	{
		file4 >> vid;
		file4 >> t;
		file4 >> rno;
		file4 >> t;
		file4 >> avgmileage;
		file4 >> t;
		getline(file4, licence, ',');
		file4 >> stat;
		file4 >> t;
		getline(file4, fuel, ',');
		file4 >> rank;
		file4 >> t;
		file4 >> rdate;
		file4 >> t;
		file4 >> rmonth;
		file4 >> t;
		file4 >> ryear;
		file4 >> t;
		file4 >> check;
		file4 >> t;
		getline(file4, feature, ',');
		file4 >> rate;
		file4 >> t;
		if (vid == a) {
			cout << "your required vehicle is:" << vid << "with following features:" << endl;
			cout << "the vehicle make model variant of:" << rdate << "/" << rmonth << "/" << ryear << endl;
			cout << "The vehicle is " << feature << endl;
			cout << "The rate of the vehicle per mile is:" << rate << endl;
			cout << "The vehicle runs on fuel type:" << fuel << " and is " << licence << " vehicle." << endl;
			cout << endl << endl;
		}
	}
}
void tms::checkcustomer()
{
	string arr, arr1;
	int d, m, y, id, trash, nid1,a;
	char trash1;
	int i = 0;
	cout << "enter id of the customer you want to print data of:";
	cin >> a;
	fstream file4("customer.txt", ios::in);
	while (!file4.eof())
	{
		getline(file4, arr, ',');
		getline(file4, arr1, ',');
		file4 >> d;
		file4 >> trash1;
		file4 >> m;
		file4 >> trash1;
		file4 >> y;
		file4 >> trash1;
		file4 >> id;
		file4 >> trash1;
		file4 >> trash;
		file4 >> trash1;
		file4 >> nid1;
		file4 >> trash1;
		if (id == a) 
		{
			cout << "driver name is:" << arr << " " << arr1 << endl;
			cout << "national id of the customer is:" << nid1 << " and " << "date of birth of customer is:" << d << "/" << m << "/" << y << endl;
		}
	}
}
void tms::checkdriverranking() 
{
	int i = 0;
	string fname1, lname1;
	int d, m, y, nid22, trash45;
	char trash22;
	float a2;
	fstream file4("driver1.txt", ios::in);
	cout << "the name of driver(s) with rating greater than 4.5 is(are):";
	while (!file4.eof())
	{
		getline(file4, fname1, ',');
		getline(file4, lname1, ',');
		/*file4 >> trash22;*/
		file4 >> a2;
		file4 >> trash22;
		file4 >> d;
		file4 >> trash22;
		file4 >> m;
		file4 >> trash22;
		file4 >> y;
		file4 >> trash22;
		file4 >> nid22;
		file4 >> trash22;
		file4 >> trash45;
		file4 >> trash22;
		file4 >> trash45;
		file4 >> trash22;
		file4 >> trash45;
		file4 >> trash22;
		if (a2 > 4.5) {
			cout << endl;
			cout << fname1 << " " << lname1 << endl;
			cout << "the national id of the driver is:" << nid22 << endl;
			cout << endl << endl;
		}
	}
}
void tms::addbonus() 
{
	int i = 0,salary;
	string fname1, lname1;
	int d, m, y, nid22, trash45;
	char trash22;
	float a2;
	fstream file4("driver1.txt", ios::in);
	cout << "the name of driver(s) with rating greater than 4.5 is(are):";
	while (!file4.eof())
	{
		getline(file4, fname1, ',');
		getline(file4, lname1, ',');
		/*file4 >> trash22;*/
		file4 >> a2;
		file4 >> trash22;
		file4 >> d;
		file4 >> trash22;
		file4 >> m;
		file4 >> trash22;
		file4 >> y;
		file4 >> trash22;
		file4 >> nid22;
		file4 >> trash22;
		file4 >> trash45;
		file4 >> trash22;
		file4 >> trash45;
		file4 >> trash22;
		file4 >> trash45;
		file4 >> trash22;
		if (a2 > 4.5) 
		{
			cout << endl;
			cout << fname1 << " " << lname1 <<" is awarded with 15% bonus in salary because of rating greater than 4.5.Kindly enter the current salary of "<<fname1<<" "<<lname1<<":"<< endl;
			cin >> salary;
			float salary1 = salary * (0.15 );
			cout << "the bonus amount is:" << salary1<< endl;
			cout << "Total salary after increase is:"<<salary  +salary1<<endl;
			cout << endl << endl;
		}
	}
}
void tms::requestservice() 
{
	int a,date,month,year;
	char t;
	int vid, rno, rdate, rmonth, ryear,miles;
	string fuel, licence, feature,type;
	float avgmileage, rank, rate;
	bool stat, check,flag=0;
	cout << "Kindly tell if you want a ride for delivery/ride or both:"<<endl;
	cout << "For delivery(press 1),For ride(press 2),For both(press 3):" << endl;
	cin >> a;
	if (a == 1) {
		type = "HTV";
	}
	else if (a == 2) {
		type = "LTV";
	}
	else if(a==3)
	{
		type = "LTV";
	}
	cout << "kindly tell the date you want to book the ride:";
	cin >> date;
	cout << "kindly tell the month you want to book the ride:";
	cin >> month;
	cout << "kindly tell the year you want to book the ride:";
	cin >> year;
	cout << "Please mention the total miles you want to ride:" << endl;
	cin >> miles;
	cout << "On the given date you have the following choices."<<endl;
	fstream file4("vehicle.txt", ios::in);
	while (!file4.eof())
	{
		file4 >> vid;
		file4 >> t;
		file4 >> rno;
		file4 >> t;
		file4 >> avgmileage;
		file4 >> t;
		getline(file4, licence, ',');
		file4 >> stat;
		file4 >> t;
		getline(file4, fuel, ',');
		file4 >> rank;
		file4 >> t;
		file4 >> rdate;
		file4 >> t;
		file4 >> rmonth;
		file4 >> t;
		file4 >> ryear;
		file4 >> t;
		file4 >> check;
		file4 >> t;
		getline(file4, feature, ',');
		file4 >> rate;
		file4 >> t;
		if (type==licence&&rdate==date&&rmonth==month&&ryear==year) 
		{
			cout << endl;
			cout << "vehicle id:" << vid << endl;
			cout << "The vehicle is " << feature/*ac or non ac*/ << endl;
			cout << "The rate of the vehicle per mile is:" << rate << endl;
			cout << "total fare:" << miles * rate <<" rupees"<< endl;
			cout << "The vehicle runs on fuel type:" << fuel << " and is " << licence/*htv or ltv*/ << " vehicle." << endl;
			cout << "rating of vehicle is:" << rank << endl;
			cout << endl << endl;
			flag = 1;
		}
	}
	if (flag == 0)
	{
		cout << "sorry,no vehicle present on the required day." << endl;
	}
}
void tms::setservice() 
{
	service obj;
	obj.setdata2();
}
void tms::samevehicle() 
{
	double frate;
	int day, year, month, hour, sec, min, vid, cid,  did,dist,counter=0;
	string  name1, city;
	char trash;
	bool flag;
	double frate1;
	int day1, year1, month1, hour1, sec1, min1, vid1, cid1, did1, dist1;
	string  name11, city1;
	char trash1;
	bool flag1;
	bool flag11 = 0;
	fstream file4("service.txt", ios::in);
	while (!file4.eof()) 
	{
		file4 >> day;
		file4 >> trash;
		file4 >> month;
		file4 >> trash;
		file4 >> year;
		file4 >> trash;
		file4 >> hour;
		file4 >> trash;
		file4 >> min;
		file4 >> trash;
		file4 >> sec;
		file4 >> trash;
		getline(file4, name1,',');
		getline(file4, city, ',');
		file4 >> dist;
		file4 >> trash;
		file4 >> flag;
		file4 >> trash;
		file4 >> frate;
		file4 >> trash;
		file4 >> cid;
		file4 >> trash;
		file4 >> did;
		file4 >> trash;
		file4 >> vid;
		file4 >> trash;
		while (!file4.eof())
		{
			file4 >> day1;
			file4 >> trash1;
			file4 >> month1;
			file4 >> trash1;
			file4 >> year1;
			file4 >> trash1;
			file4 >> hour1;
			file4 >> trash1;
			file4 >> min1;
			file4 >> trash1;
			file4 >> sec1;
			file4 >> trash1;
			getline(file4, name11, ',');
			getline(file4, city1, ',');
			file4 >> dist1;
			file4 >> trash1;
			file4 >> flag1;
			file4 >> trash1;
			file4 >> frate1;
			file4 >> trash1;
			file4 >> cid1;
			file4 >> trash1;
			file4 >> did1;
			file4 >> trash1;
			file4 >> vid1;
			file4 >> trash1;
			if (vid1 == vid) {
				counter++;
				if(counter>1)
				{
					cout << "vehicle with id " << vid << " is used by the customers multiple times." << endl;
					cout << "vehicle is used by:" << name1<<"(id:"<<cid<<")"<< " and " << name11 << "(id:" << cid1 << ")" << endl;
					flag11 = 1;
				}
			}
		}
	}
	if (flag11 == 0) {
		cout << "No use of vehicle more than once."<<endl;
	}
}
void tms::samedriver() 
{
	int i = 0,count=0;
	string fname1, lname1;
	int d2, m, y, nid22, trash45;
	char trash22;
	int i1 = 0;
	string fname11, lname11;
	int d1, m1, y1, nid221, trash451;
	char trash221;
	fstream file4("driver.txt", ios::in);
	while (!file4.eof())
	{
		getline(file4, fname1, ',');
		getline(file4, lname1, ',');
		/*file4 >> trash22;*/
		file4 >> d2;
		file4 >> trash22;
		file4 >> m;
		file4 >> trash22;
		file4 >> y;
		file4 >> trash22;
		file4 >> nid22;
		file4 >> trash22;
		file4 >> trash45;
		file4 >> trash22;
		file4 >> trash45;
		file4 >> trash22;
		file4 >> trash45;
		file4 >> trash22;
		int i = 0;
		string fname1, lname1;
		int d, m, y, nid22, trash45;
		char trash22;
		fstream file4("driver.txt", ios::in);
		while (!file4.eof())
		{
			getline(file4, fname11, ',');
			getline(file4, lname11, ',');
			/*file4 >> trash22;*/
			file4 >> d1;
			file4 >> trash221;
			file4 >> m1;
			file4 >> trash221;
			file4 >> y1;
			file4 >> trash221;
			file4 >> nid221;
			file4 >> trash221;
			file4 >> trash451;
			file4 >> trash221;
			file4 >> trash451;
			file4 >> trash221;
			file4 >> trash451;
			file4 >> trash221;
			if (d1 == d2) 
			{
				count++;
				if (count > 1)
				{
					cout << "driver:" << fname1 << " " << lname1 << " and driver:" << fname11 << " " << lname11 << " completed their deliveries on the same day."<<endl;
				}
			}
			cout << endl << endl;
		}
	}
}
void tms::pendingservice()
{

	int date, month1, year1;
	cout << "enter the day where you want to calculate to know the pending services:";
	cin >> date;
	cout << "enter month:";
	cin >> month1;
	cout << "enter year:";
	cin >> year1;
	double frate;
	int day, year, month, hour, sec, min, vid, cid, did, dist, counter = 0;
	string  name1, city;
	char trash;
	bool flag;
	fstream file4("service.txt", ios::in);
	while (!file4.eof())
	{
		file4 >> day;
		file4 >> trash;
		file4 >> month;
		file4 >> trash;
		file4 >> year;
		file4 >> trash;
		file4 >> hour;
		file4 >> trash;
		file4 >> min;
		file4 >> trash;
		file4 >> sec;
		file4 >> trash;
		getline(file4, name1, ',');
		getline(file4, city, ',');
		file4 >> dist;
		file4 >> trash;
		file4 >> flag;
		file4 >> trash;
		file4 >> frate;
		file4 >> trash;
		file4 >> cid;
		file4 >> trash;
		file4 >> did;
		file4 >> trash;
		file4 >> vid;
		file4 >> trash;
		if (day == date && month1 == month && year1 == year) 
		{
			cout << "driver " << name1 << " has to cover a distance of " << dist << " to go to city " << city <<" on the given date that is "<<date<<"/"<<month1<<"/"<<year1<<"."<<endl;
		}
	}
}
void tms::pendingdriver() 
{
	string name11;
	cout << "enter the driver you want o print the srvices of:" << endl;
	cin >> name11;
	double frate;
	int day, year, month, hour, sec, min, vid, cid, did, dist, counter = 0;
	string  name1, city;
	char trash;
	bool flag;
	fstream file4("service.txt", ios::in);
	while (!file4.eof())
	{
		file4 >> day;
		file4 >> trash;
		file4 >> month;
		file4 >> trash;
		file4 >> year;
		file4 >> trash;
		file4 >> hour;
		file4 >> trash;
		file4 >> min;
		file4 >> trash;
		file4 >> sec;
		file4 >> trash;
		getline(file4, name1, ',');
		getline(file4, city, ',');
		file4 >> dist;
		file4 >> trash;
		file4 >> flag;
		file4 >> trash;
		file4 >> frate;
		file4 >> trash;
		file4 >> cid;
		file4 >> trash;
		file4 >> did;
		file4 >> trash;
		file4 >> vid;
		file4 >> trash;
		if (name11==name1)
		{
			cout << "driver " << name1 << " has to cover a distance of " << dist << " to go to city " << city <<"."<< endl;
		}
	}
}
void tms::cancelservice()
{
	/*cout << "your cancelled services are:"<<endl;
	fstream file4("cancelservice.txt", ios::in);
	while (!file4.eof())
	{
		string deleteline = '\0';
		string line;
		string fname;
		ifstream fin;
		fin.open("driver.txt");
		ofstream fout;
		fout.open("servicecancel.txt");
		ofstream temp;
		temp.open("temp1122.txt");
		cout << "enter  name of driver:";
		cin >> fname;
		while (getline(fin, line))
			fout << line << endl;
		{
			if (line[0] == fname[0] && line[1] == fname[1])
			{
				line.replace(line.find(fname), line.length(), "");
				temp << line << endl;
			}
			else
			{
				temp << line << endl;
			}
		}
		temp.close();
		fin.close();
		rename("driver.txt", "temp1122.txt");
		cout << "You can check deleted driver/updated data from file temp1122." << endl;
	}*/
}
void tms::completeservice() 
{
	string name11;
	cout << "enter the driver name:";
	cin >> name11;
	double frate;
	int day, year, month, hour, sec, min, vid, cid, did, dist, counter = 0;
	string  name1, city;
	char trash1='.';
	bool flag=1;
	char trash1123 = ',';
	fstream file4("service.txt", ios::out);
	{
		cout << "day:";
		cin >> day;
		cout << "month:";
		cin >> month;
		cout << "year:";
		cin >> year;
		cout << "hour:";
		cin >> hour;
		cout << "min:";
		cin >> min;
		cout << "second:";
		cin >> sec;
		cout << "vehicle id:";
		cin >> vid;
		cout << "customer id:";
		cin >> cid;
		cout << "driver id:";
		cin >> did;
		cout << "distance:";
		cin >> dist;
		cout << "frate:";
		cin >> frate;
		cout << "cid:";
		cin >> cid;
		cout << "did:";
		cin >> did;
		cout << "vid:";
		cin >> vid;

		file4 << day;
		file4 << trash1123;
		file4 << month;
		file4 << trash1123;
		file4 << year;
		file4 << trash1123;
		file4 << hour;
		file4 << trash1123;
		file4<< min;
		file4 << trash1123;
		file4 <<sec;
		file4 << trash1123;
		file4 << name1;
		file4 << trash1123;
		file4 << city;
		file4 << trash1123;
		file4 << dist;
		file4 << trash1123;
		file4 << flag;
		file4 << trash1123;
		file4 << frate;
		file4 << trash1123;
		file4 << cid;
		file4 << trash1123;
		file4 << did;
		file4 << trash1123;
		file4 << vid;
		file4 << trash1123;
	}
}
void tms::checkdriver()
{
	/*
	char t; int a;
	int vid, rno, rdate, rmonth, ryear;
	string fuel, licence, feature;
	float avgmileage, rank, rate;
	bool stat, check;
	cout << "enter the vehicle id the driver is driving in which you want to get details:";
	cin >> a;
	fstream file4("vehicle.txt", ios::in);
	while (!file4.eof())
	{
		file4 >> vid;
		file4 >> t;
		file4 >> rno;
		file4 >> t;
		file4 >> avgmileage;
		file4 >> t;
		getline(file4, licence, ',');
		file4 >> stat;
		file4 >> t;
		getline(file4, fuel, ',');
		file4 >> rank;
		file4 >> t;
		file4 >> rdate;
		file4 >> t;
		file4 >> rmonth;
		file4 >> t;
		file4 >> ryear;
		file4 >> t;
		file4 >> check;
		file4 >> t;
		getline(file4, feature, ',');
		file4 >> rate;
		file4 >> t;
		if (vid == a) {
			cout << "your vehicle driver is using is " << vid << "with following features:" << endl;
			cout << "the vehicle make model variant of:" << rdate << "/" << rmonth << "/" << ryear << endl;
			cout << "The vehicle is " << feature << endl;
			cout << "The rate of the vehicle per mile is:" << rate << endl;
			cout << "The vehicle runs on fuel type:" << fuel << " and is " << licence << " vehicle." << endl;
			cout << endl << endl;
		}
	}*/
	string name11;
	cout << "enter the driver you want to print the srvices of:" << endl;
	cin >> name11;
	double frate;
	int day, year, month, hour, sec, min, vid, cid, did, dist, counter = 0;
	string  name1, city;
	char trash;
	bool flag;
	fstream file4("service.txt", ios::in);
	while (!file4.eof())
	{
		file4 >> day;
		file4 >> trash;
		file4 >> month;
		file4 >> trash;
		file4 >> year;
		file4 >> trash;
		file4 >> hour;
		file4 >> trash;
		file4 >> min;
		file4 >> trash;
		file4 >> sec;
		file4 >> trash;
		getline(file4, name1, ',');
		getline(file4, city, ',');
		file4 >> dist;
		file4 >> trash;
		file4 >> flag;
		file4 >> trash;
		file4 >> frate;
		file4 >> trash;
		file4 >> cid;
		file4 >> trash;
		file4 >> did;
		file4 >> trash;
		file4 >> vid;
		file4 >> trash;
		if (name11[0] == name1[0])
		{
			cout << "driver " << name1 << " has to cover a distance of " << dist << " to go to city " << city << "." << endl;
		}
	}
}
void tms::multiplelicense() 
{
}
int main()
{
	tms t1;
	int a,vid;
	cout << "enter 1 to add customer:"<<endl;
	cout << "enter 2 to add a driver:" << endl;
	cout << "enter 3 to remove a driver:" << endl;
	cout << "enter 4 to print list of customers:" << endl;
	cout << "enter 5 to print the list of drivers available:" << endl;
	cout << "enter 6 to print the list of vehicles available:" << endl;
	cout << "enter 7 to print complete details and service history of a particular vehicle:" << endl;
	cout << "enter 8 to print complete info of a particular customer(id required):"<<endl;
	cout << "enter 9 to complete history of the driver(including services)||NOTICE:driver id required||:"<<endl;
	cout << "enter 10 to print drivers with ranking greater than 4.5:"<<endl;
	cout << "enter 11 to print list of drivers having multiple licenses:"<<endl;//not done
	cout << "enter 12 to print updated salary based on ranking:"<<endl;
	cout << "enter 13 to add a request for a ride/delivery:"<<endl;
	cout << "enter 14 to cancel a booking:(you will be charged 5% of the total value you are paying for the service):"<<endl;//not done
	cout << "enter 15 to complete a service:" << endl;//not done
	cout << "enter 16 to print details of all Customers, who used the same vehicle in a ride service on a different date." << endl;
	cout << "enter 17 to print list of drivers who completed their job on the same day:" << endl;
	cout << "enter 18 to all pending services on a particular date:" << endl;
	cout << "enter 19 to print details of all pending services of a particular driver:" << endl;
	cout << "enter 20 to print details of all canceled services by a customer:" << endl;
	cout << "enter 21 to set service:" << endl;
	cin >> a;
	if (a == 1)
	{
		t1.addcustomer();
	}
	else if (a == 2) 
	{
		t1.adddriver();
	}
	else if (a == 3) 
	{
		t1.removedriver();
	}
	else if (a == 4) 
	{
		t1.printcustomers();
	}
	else if (a == 5) 
	{
		t1.printdriver();
	}
	else if (a == 6)
	{
		t1.printvehicle();
	}
	else if (a == 7) 
	{
		t1.checkspec();
	}
	else if (a == 8) 
	{
		t1.checkcustomer();
	}
	else if (a == 9) 
	{
		t1.checkdriver();
	}
	else if (a == 10)
	{
		t1.checkdriverranking();
	}
	else if (a==11) 
	{
		t1.multiplelicense();
	}
	else if (a == 12) 
	{
		t1.addbonus();
	}
	else if (a==13) 
	{
		t1.requestservice();
	}
	else if (a == 14) {
		t1.cancelservice();
	}
	else if (a == 15) {
		t1.completeservice();
	}
	else if (a == 21)
	{
		t1.setservice();
	}
	else if (a == 16) 
	{
		t1.samevehicle();
	}
	else if (a == 17) 
	{
		t1.samedriver();
	}
	else if (a == 18) 
	{
		t1.pendingservice();
	}
	else if (a == 19) 
	{
		t1.pendingdriver();
	}
	else if (a == 20) 
	{
		t1.cancelservice();
	}
	return 0;
}
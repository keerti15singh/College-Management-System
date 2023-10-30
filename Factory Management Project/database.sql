create database manufacturing;
use manufacturing;
create table ManufacturingUnit( Id numeric(7),primary key (Id),name varchar(25),streetno varchar(25),state varchar(25),city varchar(25),country varchar(25));
alter table ManufacturingUnit
add MRID numeric(10);
create table productionUnit(Puid numeric (7),primary key(Puid),MID numeric(7),foreign key(MID)references ManufacturingUnit(Id));
create table WareHouse(Wid numeric (7),primary key(Wid),MID numeric(7),foreign key(MID)references ManufacturingUnit(Id));
create table category(CategoryId numeric(7),primary key(CategoryId),CategoryName varchar(25),Puid numeric (7),foreign key(Puid)references productionUnit(Puid));
create table machines(MachineId numeric(7),primary key(MachineId),MachineName varchar(25),Quantity numeric(10));
create table rawmaterials(RawMaterialId numeric(7),primary key(RawMaterialID),RawMaterialName varchar(25),Quantity numeric(10));
create table products(ProductId numeric(10),primary key(ProductId),ProductName varchar(25),PricePerUnit numeric(55),CategoryId numeric(7),
foreign key(CategoryId)references category(CategoryId),RMID numeric(7),MID numeric(7),
foreign key(RMID) references rawmaterials(RawMaterialId), foreign key(MID) references machines(MachineId));
create table stocks(StockId numeric(10),primary key(StockId),Quantity numeric(10),PID numeric(10),foreign key(PID) references products(ProductId));

create table customers(CustomerId numeric(10),primary key(CustomerId),fname varchar(30),mname varchar(30),lname varchar(30),city varchar(100),state varchar(100));
create table CustomerPhoneNumber(CID numeric(10),foreign key(CID) references customers(CustomerId),phoneno numeric(10),primary key(phoneno));
create table Orders(OrderId numeric(10),CID numeric(10),foreign key(CID) references customers(CustomerId),orderstatus varchar(30),orderdate DATE,Requireddate DATE
,MRID numeric (10),foreign key(MRID) references employee(EID),primary key(OrderId));
create table OrderItems(quantity numeric(10),listprice numeric(10),discount numeric(10),OrderId numeric(10),foreign key(OrderId) references Orders(OrderId)
,PId numeric(10),foreign key(PId) references products(ProductId));
create table Employee(Ename varchar(30),Address varchar(100),gender varchar(10),dob date,doj date,EID numeric(10),primary key(EID), MID numeric(7), 
foreign key(MID) references ManufacturingUnit(Id));
create table worker(MRID numeric(10),foreign key(MRID) references Employee(EID),PId numeric(10),foreign key(Pid) references products(ProductId),primary key(Pid,
MRID));

create table marketingrepresentative(MRID numeric(10),foreign key(MRID) references Employee(EID),primary key(MRID));
create table manager(MRID numeric(10),foreign key(MRID) references Employee(EID),primary key(MRID));
alter table ManufacturingUnit add
foreign key(MRID) references manager(MRID);
insert into customers(CustomerId,fname,mname,lname,CITY,STATE) values ("100001","Ivan","A"," Bayross","Mumbai","Maharashtra");
insert into customers(CustomerId,fname,mname,lname,CITY,STATE) values ("100002","Mamta","K","Muzumdar","Madras","Tamil Nadu");
insert into customers(CustomerId,fname,mname,lname,CITY,STATE) values ("100003","Chhaya","M"," Bankar","Mumbai","Maharashtra");
insert into customers(CustomerId,fname,mname,lname,CITY,STATE) values ("100004","Ashvini","A","Joshi","Bangalore","Karnataka");
insert into customers(CustomerId,fname,mname,lname,CITY,STATE) values ("100005","Hancel","G"," Colaco","Mumbai","Maharashtra");
insert into customers(CustomerId,fname,mname,lname,CITY,STATE) values ("100006","Deepak","K","Sharma","Mangalore","Karnataka");
insert into Orders values("19001","100001","In Process","2020-06-12","2022-07-02","300001");
insert into Orders values("19002","100002","Cancelled","2018-06-25","2020-06-02","300002");
insert into Orders values("46865","100003","Fulfilled","2019-02-18","2020-02-02","300003");
insert into Orders values("19003","100001","Fulfilled","2020-04-03","2021-02-02","300001");
insert into Orders values("46866","100004","Cancelled","2022-05-20","2024-05-02","300002");
insert into Orders values("19008","100005","In Process","2021-05-24","2024-07-02","300004");
insert into manufacturingunit (Id,name,streetno,state,city,country,MRID)values("1","ClassmateFActory","2","Punjab","Jalandhar","India","300007");
insert into productionunit values("101","1");
insert into productionunit values("102","1");
insert into category values("1011","Pencils","101");
insert into category values("1012","Pens","102");
insert into rawmaterials values("501","Wood","100");
insert into rawmaterials values("502","Plastic","100");
insert into rawmaterials values("503","Lead","80");
insert into machines values("401","WeldingMachine","10");
insert into machines values("402","XYZ","12");
insert into products values("700001","Classmate_HB",10,"1011","501","401");
insert into products values("700002","Classmate_DarkWood",12,"1011","501","401");
insert into products values("700003","Classmate_DaVinci",15,"1011","501","401");
insert into products values("700004","Classmate_Octane",10,"1012","502","402");
insert into products values("700005","Classmate_Smoothie",50,"1012","502","402");
insert into products values("700006","Classmate_PollaxBlue",10,"1012","502","402");
insert into products values("700007","Classmate_Neon",20,"1012","502","402");
insert into stocks values(10001,100,"700001");
insert into stocks values(10002,100,"700002");
insert into stocks values(10003,100,"700003");
insert into stocks values(10004,100,"700004");
insert into stocks values(10005,100,"700005");
insert into stocks values(10006,100,"700006");
insert into stocks values(10007,100,"700007");

insert into employee values("Ayan_Nelson","abcNagar_Jal","M","1986-06-25","2006-09-09","300001","1");
insert into employee values("Amit_Desai","aefNagar_Jal","M","1982-07-04","2002-08-12","300002","1");
insert into employee values("Vikram_Singh","decNagar_Jal","M","1992-05-05","2010-12-02","300003","1");
insert into employee values("Joe_Styles","abcNagar_Jal","M","1990-04-02","2008-05-02","300004","1");
insert into employee values("Abhiraj_Rajvansh","dmccNagar_Jal","M","1989-03-09","2007-05-02","300005","1");
insert into employee values("Rahul_Kumar","aefNagar_Jal","M","1990-04-12","2008-05-02","300006","1");
insert into employee values("Raghuram_Verma","pqrNagar_Jal","M","1982-12-12","2002-12-03","300007","1");
insert into employee values("Ramya_Sen","ghiNagar_Jal","F","1993-03-25","2012-10-14","300008","1");
insert into employee values("Sheetal_Mehra","dmcNagar_Jal","F","1986-12-16","2008-11-12","300009","1");
insert into marketingrepresentative values("300001");
insert into marketingrepresentative values("300002");
insert into marketingrepresentative values("300003");
insert into marketingrepresentative values("300004");
insert into manager values("300007");
insert into worker values("300005","700001");
insert into worker values("300006","700002");
insert into worker values("300008","700003");
insert into worker values("300009","700004");
insert into orderitems values("100","18","20","19002","700007");
insert into orderitems values("200","9","10","19003","700006");
insert into orderitems values("100","45","30","19008","700005");
insert into orderitems values("120","9","10","46865","700004");
insert into orderitems values("300","12","20","46866","700003");
insert into orderitems values("200","10","10","19002","700002");
insert into orderitems values("500","18","10","19003","700007");
insert into orderitems values("450","9","10","19001","700001");
insert into manufacturingunit(MRID) values("300007");
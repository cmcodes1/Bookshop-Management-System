//***************************************************************//HEADERFILEUSEDINPROJECT//****************************************************************#include<conio.h>#include<stdio.h>#include<process.h>#include<fstream.h>#include<iomanip.h>#include<string.h>#include<ctype.h>structorder{intbookid1;charname1[50];charpub1[50];intqty1;floatprice1,dis1;}o1[50];intorderk=0;voidcopyfile(intbok1,ordero11[],int&c1,intqt2);voidcopyme(intk,orderorder1[],intq1,int&c2);voidintromain();intgetrollno();voiddisplay_all();voidbook_tabular();voidmodify_record(intn);voiddelete_record(intn);voidagainopenandclose();intsearch(intp);voidchangeqty(intpr1,intq11);//***************************************************************//CLASSUSEDINPROJECT//****************************************************************classbooks{intbookid;charname[50];charpub[50];intqty;floatprice,dis;public:books(){qty=0;price=0;dis=0;}voidmodifydata(intn1,charsnm[15],charpubnm[15],intq);//*****************************************************************************voidshowdatamulti(){gotoxy(5,7);cout<<"======================================================================";gotoxy(10,8);cout<<"BOOKNO:";gotoxy(30,8);cout<<bookid;gotoxy(40,8);cout<<"TITLEOFBOOK:";gotoxy(60,8);cout<<name;gotoxy(10,9);cout<<"PUBLISHER:";gotoxy(30,9);cout<<pub;gotoxy(40,9);cout<<"BOOKPRICE:";gotoxy(60,9);cout<<price;gotoxy(10,10);cout<<"QUANTITY:";gotoxy(30,10);cout<<qty;gotoxy(40,10);cout<<"DISCOUNT";gotoxy(60,10);cout<<dis;gotoxy(5,11);cout<<"=====================================================================";}//*****************************************************************************voidcreate_book(intrn1){//**********************************************gotoxy(5,7);cout<<"======================================================================";gotoxy(10,8);cout<<"BOOKID:";bookid=rn1;gotoxy(24,8);cout<<bookid;gotoxy(35,8);cout<<"TITLENAME:";gotoxy(54,8);cin>>name;gotoxy(10,9);cout<<"PUBLISHER:";gotoxy(22,9);cin>>pub;gotoxy(35,9);cout<<"QUANTITY";gotoxy(54,9);cin>>qty;gotoxy(10,11);cout<<"PRICE";gotoxy(25,11);cin>>price;gotoxy(35,11);cout<<"DISCOUNT";gotoxy(45,11);cin>>dis;gotoxy(5,12);cout<<"=====================================================================";}voidshow_book(){//********************************gotoxy(5,7);cout<<"======================================================================";gotoxy(10,8);cout<<"BOOKID:";//rollno=rn1;gotoxy(25,8);cout<<bookid;gotoxy(35,8);cout<<"TITLEOFBOOK:";gotoxy(54,8);cout<<name;gotoxy(10,9);cout<<"PUBLISHER:";gotoxy(25,9);cout<<pub;gotoxy(35,9);cout<<"PRICEOFPRODUCT:";gotoxy(54,9);cout<<price;gotoxy(10,10);cout<<"DISCOUNT:";gotoxy(25,10);cout<<dis<<"%";gotoxy(35,10);cout<<"QUANTITY:";gotoxy(54,10);cout<<qty;gotoxy(5,11);cout<<"=====================================================================";}//-----------------------showdatatabularform----------------------voidshowall(intc){gotoxy(1,c);cout<<bookid<<setw(17)<<name<<setw(11)<<pub<<setw(10)<<"Rs."<<price<<setw(15)<<qty<<setw(12)<<dis<<"%";}//-----------------------endshere------------------------------------intretpno(){returnbookid;}floatretprice(){returnprice;}char*getpub(){returnpub;}char*getname(){returnname;}intgetqty(){returnqty;}floatretdis(){returndis;}voidsetqty(intq21){qty=q21;}};//classendshere//***************************************************************//globaldeclarationforstreamobject,object//****************************************************************//*************************modifybookvoidbooks::modifydata(intn1,charsnm[15],charpubnm[15],intq){chartmpnm[40],tmpnm2[40];gotoxy(5,14);cout<<"===================WANTTOMODIFY===============================";gotoxy(10,15);cout<<"BOOKID:";bookid=n1;gotoxy(25,15);cout<<bookid;gotoxy(40,15);strcpy(name,snm);cout<<"TITLEOFBOOK:";gotoxy(60,15);cout<<name;gotoxy(10,17);cout<<"Wanttochangethenameofbook";gotoxy(50,17);intflag=0;while(1){gets(tmpnm);if(strlen(tmpnm)!=0){flag=1;break;}if(strlen(tmpnm)==0){flag=0;break;}}if(flag==1){strcpy(name,tmpnm);}else{}gotoxy(1,18);strcpy(pub,pubnm);//****************PUBLISHERNAMETOBEMODIFYcout<<"PUBLISHERSNAME:";gotoxy(20,18);cout<<pub;gotoxy(35,18);cout<<"WanttochangethePUBLISHER";gotoxy(65,18);flag=0;while(1){gets(tmpnm2);if(strlen(tmpnm2)!=0){flag=1;break;}if(strlen(tmpnm2)==0){flag=0;break;}}if(flag==1){strcpy(pub,tmpnm2);}//*****************PUBLISHERNAMETOBEMODIFIEDENDSHEREgotoxy(5,19);cout<<"********MODIFY**PRODUCTPRICE-QUANTITY-DISCOUNT***********";//****************************************************gotoxy(5,20);cout<<"PRICE:";gotoxy(15,20);floattmppr=0;flag=-1;while(1){cin>>tmppr;if(tmppr!=0){flag=1;break;}else{flag=0;break;}}if(flag==1){price=tmppr;}else{}//****************************************************//****************************************************gotoxy(22,20);cout<<"INCREASEQUANTITY:";gotoxy(45,20);inttmpqty=0;cin>>tmpqty;qty=q;qty=qty+tmpqty;//***************************************************//***************************************************gotoxy(50,20);cout<<"DISCOUNT:";gotoxy(63,20);floattmpdis=0;cin>>tmpdis;dis=tmpdis;//*****************************************gotoxy(5,22);cout<<"=====================================================================";}//**************************classfunctionoutsidefstreamfp;bookspr;//***************************************************************//functiontowriteinfile//****************************************************************voidwrite_book(){fp.open("book.dat",ios::out|ios::app);clrscr();intromain();intrnn=getrollno();if(rnn>100){rnn=1;}pr.create_book(rnn);fp.write((char*)&pr,sizeof(books));fp.close();gotoxy(10,20);cout<<"***************TheBOOKSRECORDENTERED*******************";cin.ignore();getch();}//********************checkthebooknumberalreadygivenornot******intgetrollno(){ifstreamobjiff;booksst;intcount=0;objiff.open("book.dat",ios::binary);objiff.seekg(0,ios::beg);if(!objiff){cout<<"Filecouldnotbeopen!!PressanyKey...";getch();}//**************temporaryhidingtheselineswhile(objiff.read((char*)&st,sizeof(books))){count++;}//***********jumptothelastlineobjiff.seekg(count-sizeof(st),ios::beg);objiff.read((char*)&st,sizeof(books));count=st.retpno();count++;objiff.close();returncount;}//***************************************************************//functiontoreadspecificrecordfromfile//****************************************************************voiddisplay_sp(intn){intflag=0;fp.open("book.dat",ios::in);if(!fp){cout<<"Filecouldnotbeopen!!PressanyKey...";getch();return;}while(fp.read((char*)&pr,sizeof(books))){if(pr.retpno()==n){clrscr();intromain();pr.show_book();flag=1;}}fp.close();if(flag==0)cout<<"\n\nrecordnotexist";getch();}//***************************************************************//functiontoplaceorderandgeneratingbillforBOOKSPURCHASED//****************************************************************voidplace_order(){ordero1[50];intc=0,pr1=0;floatamt=0,damt=0,total=0,ttaxt=0;intk=0,q1;charch='Y';clrscr();book_tabular();clrscr();intromain();gotoxy(30,4);cout<<"============================";gotoxy(30,5);cout<<"PLACEYOURORDER";gotoxy(30,6);cout<<"============================";do{clrscr();gotoxy(5,10);cout<<"EnterTheBOOKNo:";gotoxy(55,10);cin>>pr1;k=search(pr1);if(k>0){gotoxy(5,12);cout<<"EntertheQuantity:";gotoxy(28,12);cin>>q1;changeqty(pr1,q1);copyme(k,o1,q1,c);}else{cout<<"BOOKnotfound";}clrscr();gotoxy(10,20);cout<<"Doyouwantpurchasemore(Yes[yorY]orNO[norN])";gotoxy(10,21);cin>>ch;}while(ch=='y'||ch=='Y');//***************whileendsbytheselinesclrscr();gotoxy(20,20);cout<<"ThankYouForPlacingTheOrder..........";getch();clrscr();intromain();gotoxy(13,5);cout<<"*************************INVOICE************************";gotoxy(1,6);cout<<"BK.No."<<setw(12)<<"TITLE"<<setw(10)<<"Qty"<<setw(15)<<"Price"<<setw(13)<<"Amount"<<setw(23)<<"Amount-discount";gotoxy(3,7);cout<<"----------------------------------------------------------------------------";intyy=8;for(intx=0;x<c;x++){gotoxy(1,yy);cout<<o1[x].bookid1;gotoxy(10,yy);cout<<o1[x].name1;gotoxy(27,yy);cout<<o1[x].qty1;gotoxy(40,yy);cout<<"Rs."<<o1[x].price1;gotoxy(50,yy);amt=o1[x].qty1*o1[x].price1;cout<<"Rs."<<amt;damt=amt-o1[x].dis1;gotoxy(65,yy);cout<<"Rs."<<damt;total+=damt;//ttaxt+=o1[x].tax1;yy++;}ttaxt=5;gotoxy(3,yy);cout<<"----------------------------------------------------------------------------";yy++;gotoxy(25,yy);cout<<"TOTAL:";gotoxy(35,yy);cout<<total;yy++;gotoxy(25,yy);cout<<"TAX%:";gotoxy(36,yy);cout<<"+"<<ttaxt;yy++;gotoxy(25,yy);cout<<"----------------------------";yy++;gotoxy(25,yy);cout<<"NETTOTAL:";gotoxy(35,yy);cout<<(total+((ttaxt*total)/100));yy++;gotoxy(3,yy);cout<<"----------------------------------------------------------------------------";//*****************changeattheabovegetch();}//********************fuctiontocopyallrecordtoastructurevoidcopyme(intk2,orderorder1[50],intq1,int&c2){ifstreamobjiff2("book.dat",ios::binary);booksbk1;objiff2.seekg(k2-sizeof(books));objiff2.read((char*)&bk1,sizeof(books));strcpy(order1[c2].name1,bk1.getname());strcpy(order1[c2].pub1,bk1.getpub());order1[c2].dis1=bk1.retdis();order1[c2].price1=bk1.retprice();//*********************copyrecord***********************order1[c2].qty1=q1;c2++;objiff2.close();}//***************************************************************//INTRODUCTIONFUNCTION//****************************************************************voidintro(){gotoxy(4,2);cout<<"****************************BOOKSHOP**********************************";gotoxy(12,4);cout<<"===========================================================";gotoxy(5,5);cout<<"****************************S=Y=S=T=E=M********************************";gotoxy(15,10);cout<<"PROJECT:";gotoxy(15,12);cout<<"MADEBY:cmcodes";gotoxy(10,14);cout<<"---------------SCHOOL:DOONPUBLICSCHOOL--------------------";getch();}//***************************************************************//ADMINSTRATORMENUFUNCTION//****************************************************************voidadmin_menu(){clrscr();charch2;intnum;//************************************************************clrscr();intromain();gotoxy(20,6);cout<<"=================ADMINMENU====================";gotoxy(22,7);cout<<"1.CREATEBOOKS";gotoxy(22,8);cout<<"2.DISPLAYALLBOOKSAVAILABEL";gotoxy(22,9);cout<<"3.SEARCHRECORD(QUERY)";gotoxy(22,10);cout<<"4.MODIFYBOOKS";gotoxy(22,11);cout<<"5.DELETEBOOK";gotoxy(22,12);cout<<"6.BACKTOMAINMENU";gotoxy(18,13);cout<<"PleaseEnterYourChoice(1-6)";gotoxy(55,13);//**********************************************************ch2=getche();switch(ch2){case'1':clrscr();write_book();break;case'2':book_tabular();//display_all();break;case'3'://********************clrscr();intromain();gotoxy(10,8);cout<<"*****ENTERTHEBOOKIDTOBESEARCHED:";gotoxy(55,9);cin>>num;display_sp(num);break;case'4':clrscr();intromain();gotoxy(10,8);cout<<"*****ENTERTHEBOOKIDTOBESEARCHEDANDMODIFY:";gotoxy(55,9);cin>>num;modify_record(num);break;case'5':clrscr();intromain();gotoxy(10,8);cout<<"*****ENTERTHEBOOKIDTOBESEARCHEDANDTODELETE:";gotoxy(55,9);cin>>num;delete_record(num);break;case'6':break;default:cout<<"\a";admin_menu();}}//***************************************************************//THEMAINFUNCTIONOFPROGRAM//****************************************************************voidmain(){charch;intro();do{//****************TEMPORARY***********************clrscr();intromain();gotoxy(20,6);cout<<"=================MAINMENU====================";gotoxy(28,7);cout<<"01.BOOKSSELLING";gotoxy(28,8);cout<<"02.ADMINISTRATOR";gotoxy(28,9);cout<<"03.EXIT";gotoxy(20,10);cout<<"==============================================";gotoxy(25,12);cout<<"PleaseSelectYourOption(1-3)";gotoxy(30,14);ch=getche();switch(ch){case'1':clrscr();orderk=0;place_order();getch();break;case'2':admin_menu();break;case'3':exit(0);default:cout<<"\a";}}while(ch!='3');}//***************mainintrovoidintromain(){clrscr();gotoxy(1,2);cout<<"*************************BOOKS********SHOP******PROJECT************************";gotoxy(1,3);cout<<"******************************************************************************";}//******************************************************************************//DISPLAYALLTHEPRODUCTTABULARFORM//******************************************************************************voidbook_tabular(){intr=0,col=10;booksst;ifstreaminFile;inFile.open("book.dat",ios::binary);if(!inFile){cout<<"Filecouldnotbeopen!!PressanyKey...";getch();return;}display_all();while(inFile.read((char*)&st,sizeof(books))){if(r<=12){r++;st.showall(col);col++;}else{gotoxy(20,30);cout<<"--------------pressanykey------------------------";getch();clrscr();display_all();col=10;r=0;}}inFile.close();getch();}//**************************tabularformsends**********************************//*******************tabularsformsheadings************************************//functiontodisplayalltherecordsofbook//**********************************************************************voiddisplay_all(){clrscr();intromain();gotoxy(1,5);cout<<"**********************BOOKSDETAILS***************************";gotoxy(1,6);cout<<"================================================================================";gotoxy(1,7);cout<<"PROD.NO"<<setw(10)<<"TITLE"<<setw(15)<<"PUBLISHER"<<setw(15)<<"PRICE"<<setw(15)<<"QUANTITY"<<setw(10)<<"DISCOUNT";gotoxy(1,8);cout<<"================================================================================";}//************************************************************//MODIFYRECORD//**********************************************************voidmodify_record(intn){booksst,temp;chartmpnm[50],tmppub[50];ifstreaminFile;intfpos=-1;inFile.open("book.dat",ios::binary);if(!inFile){cout<<"Filecouldnotbeopen!!PressanyKey...";getch();return;}intflag=0;while(inFile.read((char*)&st,sizeof(books))){if(st.retpno()==n){clrscr();intromain();st.showdatamulti();flag=1;}}inFile.close();if(flag==0)cout<<"\n\nrecordnotexist";else{//*******modifyingtherecordsstartsherefstreamFile;File.open("book.dat",ios::binary|ios::in|ios::out);if(!File){cout<<"Filecouldnotbeopen!!PressanyKey...";getch();return;}while(File.read((char*)&st,sizeof(books))){if(st.retpno()==n){fpos=(int)File.tellg();break;}}File.seekp(fpos-sizeof(books),ios::beg);strcpy(tmpnm,st.getname());strcpy(tmppub,st.getpub());intq1=st.getqty();gotoxy(1,12);cout<<"*****************************************************************************";gotoxy(1,13);cout<<"================ENTERNEWVALUESFORTHERECORDSGIVENABOVE=================";temp.modifydata(n,tmpnm,tmppub,q1);File.write((char*)&temp,sizeof(books));File.close();}}//*****************************************************************************//DELETETHERECORDOFTHEBOOKSNOTAVAILABLE//****************************************************************************voiddelete_record(intn){booksst;ifstreaminFile;inFile.open("book.dat",ios::binary);if(!inFile){cout<<"Filecouldnotbeopen!!PressanyKey...";getch();return;}intflag=0;while(inFile.read((char*)&st,sizeof(books))){if(st.retpno()==n){clrscr();intromain();st.showdatamulti();flag=1;}}inFile.close();charch;if(flag==0)cout<<"\n\nrecordnotexist";else{//*******deletionoftherecordsstartsfromheregotoxy(1,15);cout<<"*****************************************************************************";gotoxy(5,16);cout<<"======DOYOUWANTTODELETETHERECORDSGIVENABOVE[YES(Y)ORNO(N)========";gotoxy(2,17);cin>>ch;if(toupper(ch)=='Y'){ofstreamoutFile;outFile.open("Temp1.dat",ios::binary);ifstreamobjiff("book.dat",ios::binary);objiff.seekg(0,ios::beg);while(objiff.read((char*)&st,sizeof(books))){if(st.retpno()!=n){outFile.write((char*)&st,sizeof(books));}}outFile.close();objiff.close();remove("book.dat");rename("Temp2.dat","book.dat");againopenandclose();gotoxy(30,20);cout<<"----------------------------RecordDeleted----------------------------------";}}getch();}//***********************deleterecordends************************************voidagainopenandclose(){ifstreaminFile;booksst;inFile.open("book.dat",ios::binary);if(!inFile){getch();return;}while(inFile.read((char*)&st,sizeof(books))){}inFile.close();}//***********************searchthebook***********************intsearch(intp){booksst;inttmprt=0;ifstreaminFile;inFile.open("book.dat",ios::binary);if(!inFile){cout<<"Filecouldnotbeopen!!PressanyKey...";getch();return-1;}intflag=0;while(inFile.read((char*)&st,sizeof(books))){if(st.retpno()==p){clrscr();intromain();st.showdatamulti();flag=1;tmprt=(int)inFile.tellg();break;}}inFile.close();if(flag==0)return1;//cout<<"\n\nrecordnotexist";else{returntmprt;}}//********************changequantity*************************voidchangeqty(intpr1,intq11){booksst;intfpos=-1;fstreamFile;File.open("book.dat",ios::binary|ios::in|ios::out);if(!File){cout<<"Filecouldnotbeopen!!PressanyKey...";getch();return;}while(File.read((char*)&st,sizeof(books))){if(st.retpno()==pr1){fpos=(int)File.tellg();break;}}File.seekp(fpos-sizeof(books),ios::beg);intq1=st.getqty();q1=q1-q11;st.setqty(q1);File.write((char*)&st,sizeof(books));File.close();}//***************************************************************//ENDOFPROJECT//

#include <iostream>
using namespace std;
class parking{
private:
    int id_no[20]; // Customers identifiers number... array size=20,
    int plate_no[20]; // array size=[20] ... can store 20 vehicle's plate_no in their respective places
    char slot_no[20];
    int i, e, m; // variables used as counters, as array subscripts.

    char cue_full; // cue to indicate parking spaces are full.
    char cue;

    char choice; // variable to accept entered choice as char type
    char vehicle; // to differentiate vehicle type.

    float mnth[20],date[20], hr[20], mins[20]; // Parking Entry date and time// array for 20 customers.
    float ehr,emins, edate,emnth ; // Parking exit date and time.
    float tmnth,thr,tmins,days,tdays ; // Variables for total hours and days to be calculated.

    float perhr, perdy; // rate of parking per hr and per day.
    float tfee; // total parking fee variable.
public:
    parking(); // Constructor .... To assign values for class member variables.

    bool valid(char choice);
    void vehicle_name();
    bool check_date(float mn, float dy);
    bool check_time(float h, float m);

    char welcome();
    void entry();
    void takeinfo();

    void ext_mngr();
    void exit();
    float calculate_fee();

    void total_spaces();
    void space_mngr();
    void parking_spaces();

    void parking_info();
};
    parking park; /// class_name object; Declaration
    parking car;
    parking truck;
    parking motorcycle;
parking::parking() /// Constructor ... effective for assigning instance variables.
{
    i=0;
    e= -1;
    cue='n';
    cue_full='n';
}
void parking::total_spaces()
{
    if(vehicle=='1')
    m=5;
    if(vehicle=='2')
    m=2;
    if(vehicle=='3')
    m=7;
}
void parking::vehicle_name() ///Prints the name of vehicle.
{
    if(vehicle=='1')
    cout<<"Car";
    else if(vehicle=='2')
    cout<<"Truck/Bus";
    else if(vehicle=='3')
    cout<<"Motorcycle";
}
bool parking:: valid(char choice) /// Validates entered choice from other functions.
{
    if( (choice>'4' || choice<'1') && (choice!= 'q')&& (choice!='Q'))
        return false;
    else
        return true;
}
void parking::parking_info()   ///Displays Parking fee information and Business Rules.
{
    cout<<"\n\n\n  ===================Code Delight Parking Business Rules==================\n";
    cout<<"\n\n     1. Parking Fees are calculated depending on duration of parking";
    cout<<"\n         and the type of vehicle. Please refer to the below list to see ";
    cout<<"\n         vehicles' respective rate.";
    cout<<"\n\n     2. If Vehicles stayed less than 2 days(48hrs), they will pay their";
    cout<<"\n         parking fees calculated by their specific vehicle's rate per hour.";
    cout<<"\n\n     3. If Vehicles stayed more than 2 days(48hrs);";
    cout<<"\n           3.1. First, they pay their first 2days(48hrs) parking calculated ";
    cout<<"\n                by their respective vehicle's rate per hour.";
    cout<<"\n           3.2. And their remaining full days(24hrs) regardless of the time  ";
    cout<<"\n                exited is calculated by the vehicle's rate per day.";
    cout<<"\n\n         Vehicle Type              Rate Per Hr.            Rate per Day ";
    cout<<"\n\n          1. Car                      1 birrs                10 birrs   ";
    cout<<"\n          2. Truck /Bus               2 birrs                15 birrs   ";
    cout<<"\n          3. MotorCycle               0.5 birrs              4  birrs   ";
    cout<<"\n\n\t\t Thank You for Using Code Delight Parking Service.";
    cout<<"\n\n\n   ===================Code Delight Parking Business Rules==================\n";
}
char parking::welcome() /// Main menu - brings choice of what to be done.
{
    cout<<"\n\n\n\t||============Welcome to Code Delight Parking Service==========||";
    cout<<"\n\t||                            Main Menu                        ||";
    cout<<"\n\t||                                                             ||";
    cout<<"\n\t|| Choose                                        #######       ||";
    cout<<"\n\t|| (1) For a new vehicle parking entry. <<    ##############   ||";
    cout<<"\n\t|| (2) To exit parked car.              <<    ##############   ||";
    cout<<"\n\t|| (3) To see available parking spaces           @@   @@       ||";
    cout<<"\n\t||     and cars parked if any.                                 ||";
    cout<<"\n\t|| (4) For information on parking rules                        ||";
    cout<<"\n\t||     and parking fees.                                       ||";
    cout<<"\n\t|| (q) to quit.                                                ||";
    cout<<"\n\t|| Your choice:  ";
    cin>>choice;
    return choice;
}
void parking::entry() ///Parks new vehicles, choosing vehicle type.
{
    again_entry:
    cout<<"\n\tPlease choose type of vehicle \n\t1.(Car) \n\t2.(Truck or Bus) \n\t3.(Motorcycle)";
    cout<<"\n\tEnter the number of your choice or q(to quit): ";
    cin>>choice;

        if( park.valid(choice) )
        {
            switch(choice)
           {
            case '1':
            car.vehicle=choice;
            car.total_spaces();
                if(car.cue_full=='y')
                    {cout<<"\n\tNo Parking Spaces available for "; car.vehicle_name();
                     cout<<". Please, Come back later."; goto last;}
            car.takeinfo();
            break;

            case '2':
            truck.vehicle=choice;
            truck.total_spaces();
                if(truck.cue_full=='y')
                    {cout<<"\n\tNo Parking Spaces available for ";truck.vehicle_name();
                    cout<<". Please, Come back later."; goto last;}
            truck.takeinfo();
            break;

            case '3':
            motorcycle.total_spaces();
                if(motorcycle.cue_full=='y')
                    {cout<<"\n\tNo Parking Spaces available for ";motorcycle.vehicle_name();
                     cout<<". Please, Come back later."; goto last;}
            motorcycle.vehicle=choice;
            motorcycle.takeinfo();
            break;
            case 'q':
            break;
           }
        }
        else
            goto again_entry;

        last:
        return;
}
void parking::takeinfo()/** Takes customers and vehicle's information, and parks the vehicle at a specific parking slot no.*/
{
    int j;
    int counter=0;
      for(j=0;j<m;j++)
    {
        if(slot_no[j]!='y')
        {
            i=j;
            j=m;
        }
    }

    cout<<"\n\n\n\t <<<<<<<<<<<<<<<<<<<<<<Information Database>>>>>>>>>>>>>>>>>>>>>";
    cout<<"\n\n\t\t Please enter Customer's Id no.: ";
    cin>>id_no[i];

    cout<<"\t\t Enter Plate no.: ";
    cin>>plate_no[i];
    j=0;
    do{
    if(j>0)
        cout<<"\t\t Incorrect value, Please enter again!\n";
    cout<<"\tEnter date Ethiopian Calendar [ month, date ]: ";
    cin>>mnth[i]>>date[i];
    j++;} while(!check_date(mnth[i],date[i]));

    j=0;
    do{
    if(j>0)
        cout<<"\t\t Incorrect value!\n";
    cout<<"\tEnter entry time [ hr<=24 and mins<=60 (only integers)]: ";
    cin>>hr[i]>>mins[i];
    j++;} while(!check_time(hr[i], mins[i]));

    cout<<"\n\t<<< "; vehicle_name();
    cout<<" with Plate No. "<< plate_no[i] ;
    cout<<" is parked at Parking Slot No."<<i+1<<"  >>>";
    slot_no[i]= 'y';

    for(int j=0;j<m;j++)
    {
        if(slot_no[j]=='y')
        {
          counter++;
        }
    }
    if(counter==m)
        cue_full='y';
}
bool parking::check_date(float mn, float dy)
{
    if(mn-int(mn)==0 && dy-int(dy)==0)
    {
        if(mn<1 || mn>13 || dy<1 || dy>30)
            return false;
        else if(mn==13 && (dy<1 || dy>6))
            return false;
        else
            return true;
    }
    else
        return false;
}
bool parking::check_time(float h, float m)
{
    if(h-int(h)==0 && m-int(m)==0)
    {
        if(h<0 || h>24 || m<0 || m>60)
            return false;
        else
            return true;
    }
    else
        return false;
}
void parking::ext_mngr()
{

    cout<<"\n\tChoose the vehicle you want to exit \n\t1.(Car) \n\t2.(Truck or Bus) \n\t3.(Motorcycle)";
    cout<<"\n\tEnter the number of your choice or q(to quit): ";
    cin>>choice;
    if(park.valid(choice))
    {
    if(choice=='1')
    {car.vehicle=choice;
    car.exit();}
    else if(choice=='2')
    {truck.vehicle=choice;
    truck.exit();}
    else if(choice=='3')
    {motorcycle.vehicle=choice;
    motorcycle.exit();}
    }
}
void parking::exit() ///Ends parking and issues parking fees to customers with receipt.
{
    int plate;
    cout<<"\n\n\n\t-=-=-=-=-=-=-=-=-=Parking Exit Window=-=-=-=-=-=-=-=-=-=-=";
    cout<<"\n\tPlease Enter the plate No of the vehicle to exit:";
    cin>>plate;

for(int j=0;j<20;j++) // searches for the vehicle with that specific number.
{
    if( plate_no[j]== plate)
    {e=j;
    } // e is the array subscript of this particular vehicle.
}

if(e==-1)
    {cout<<"\n\t<<<<<<< No ";vehicle_name();cout<<" is currently parked with plate no. "<<plate<<">>>>>>>>>";}
else
    {cout<<"\n\t>> >>> >>>>> Vehicle is being checked out....";
    calculate_fee();
    cout<<"\n\n\n\t~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=";
    cout<<"\n\t~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~==~=~=~=~";
    cout<<"\n\t\t\tParking Fee Receipt";
    cout<<"\n\t\t   Code Delight Parking Service\tDate     "<<edate<<"/"<<emnth<<"/2009 E.C.";
    cout<<"\n\tCustomer's Id: "<<id_no[e];
    cout<<"\n\tPlate No: "<<plate_no[e];
    cout<<"\n\tVehicle type: ";vehicle_name();
    cout<<"\n\tEntry Date and time: "<<date[e]<<"/"<<mnth[e]<<"/2009 E.C. @ time "<<hr[e]<<":"<<mins[e];
    cout<<"\n\tCurrent exit date: "<<edate<<"/"<<emnth<<"/2009 E.C.";
    if(cue=='y')
    {cout<<" @ time "<<ehr<<":"<<emins;
    cout<<"\n\tTotal hours parked: "<<thr<<" hrs";}
    else
        cout<<"\n\tTotal days parked: "<<tdays<<" days";
    cout<<"\n\tRate per hour for your ";
    vehicle_name();
    cout<<" : "<<perhr<<" br/hr.";
    if(cue!='y')
        {cout<<"\n\t And Rate per day for vehicle type ";vehicle_name();cout<<" is: "<<perdy<<" br/day";
        cout<<"\n\tTotal Cost= "<<tdays<<"-2(days)"<<"*"<<perdy<<"(br/day)"<<" + "<<"48hrs*"<<perhr<<"br/hr";}
    else
        cout<<"\n\tTotal Cost= "<<thr<<"hrs * "<<perhr<<"br/hr";
    cout<<"\n\n\t\t==========Your Total cost is: "<<tfee<<" birrs.===========\n";
    cout<<"\n\t\t\tThank you for choosing code delight service\n\t\t\t\tPlease Come back again.";
    cout<<"\n\t~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=";
    cout<<"\n\t~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=\n\n\n\n";
    cout<<"\n\n\n\t>>>>>>>>>>>";vehicle_name();

    slot_no[e]='n';
    plate_no[e]=-1;
    cout<<"Parking slot no."<<e+1<<" is cleared. Free to park. <<<<<<<<<<<";
    cue_full='n';
    e=-1;
    }

}
float parking::calculate_fee() ///Calculates total parking fee and returns it as float.
{
    float const trh=2, trd=15; // trh =train/bus rate per hour and train/bus rate per day
    float const crh=1, crd=10; //c-car's rate
    float const mrh=0.5, mrd=4; //m- motorcycle's rate

    switch(vehicle)
    {
        case '1':
        perhr=crh;
        perdy=crd;
        break;
        case '2':
        perhr=trh;
        perdy=trd;
        break;
        case '3':
        perhr=mrh;
        perdy=mrd;
    }
    again:

    cout<<"\n\tEnter exit date [month, date]: ";
    cin>>emnth>>edate;

    tmnth= emnth - mnth[e];
    days= edate-date[e];
    tdays= (tmnth*30) + days;
    if(tdays<0)
        {cout<<"\t<<<<<<Incorrect entry, please enter again >>>>>>>\n";
        goto again;}
    else if(tdays>3)
        {optionforday3:
        cue='n';
        tfee= (tdays-2) *perdy + (perhr*48);}
    else
    {
        cue='y';
        cout<<"\n\tEnter exit time [hr<=24 and mins<=60]: ";
        cin>>ehr>>emins;
        thr = ehr - hr[e];
        if(thr<0 && tdays>0)
            {tdays--;
            thr+=24;}
        tmins= emins- mins[e];
            if(tmins<0 && thr>0)
            {
                thr--;
                tmins+=60;
            }
        thr=(thr+tmins/60)+(tdays*24);
        if(thr>48)
            goto optionforday3;
        else if(thr<=0)
            {cout<<"\t<<<<<< Incorrect enter, please enter again >>>>>>>\n";
        goto again;}
    tfee=thr*perhr;
    }
return tfee;
}
void parking::space_mngr()
{
    car.vehicle = '1';
    car.total_spaces(); car.parking_spaces();
    truck.vehicle='2';
    truck.total_spaces(); truck.parking_spaces();
    motorcycle.vehicle='3';
    motorcycle.total_spaces(); motorcycle.parking_spaces();
}
void parking::parking_spaces() ///Sorts parking spaces, shows free available spaces.
{
    int i, j;
    cout<<"\n\n\n\t\t"; vehicle_name();
    cout<<" Parking space\t\tParked Vehicle\n";
    for(i=0, j=0;i<m;i++)
    {
        cout<<"\n";
        cout<<"\t\t    "<<i+1<<".";
        if(slot_no[i] == 'y')
            {
                cout<<"\t\t.........\t"; vehicle_name();
                cout<<" with Plate no."<<plate_no[i]<<"\t";
            }
        else
            {cout<<"\t\t.........\tFree";
        j++;}
    }
    cout<<"\n\n\tTotal Available Free "; vehicle_name(); cout<<" Parking Spaces are: "<<j;
    if(j==0)
        cue_full='y';
}
int main() /// Main function of c++. Calls other function and sorts order of execution.
{
    again_main:
    char option, check='n';
    option=park.welcome(); //accepts choice from welcome function.

        if( park.valid(option) )
        {
            switch(option)
            {
            case '1':
            park.entry();
            break;
            case '2':
            park.ext_mngr();
            break;
            case '3':
            park.space_mngr();
            break;
            case '4':
            park.parking_info();
            break;
            case 'q': case 'Q':
                cout<<"\n    If you quit, all saved information will be lost."<<endl;
                cout<<"    Are you sure you want to quit? (q) to quit: ";
                cin>>check;
            if(check=='q'||check=='Q')
                {cout<<"\n\n\t\t Thank You for Using Code Delight Parking Service.";
                cout<<"\t\t\t\t\t\t\tGood Bye!\n\n";
                goto lastend;}
            break;
            }
        }
        else
            cout<<"\nPlease enter only from the listed options.";

    while(check!='C' && check!='c')
    {
        cout<<"\n\nEnter 'c' to continue: ";
        cin>>check;
    }

    goto again_main;
    lastend:
    return 0;
}

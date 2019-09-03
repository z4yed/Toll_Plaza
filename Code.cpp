#include<iostream>
using namespace std;

const int m = 1000;


class Toll_Plaza
{
private:
                int buscount, allowed_truckcount, banned_truckcount, bykecount, carcount, pickupcount;

                int toll_bus[m];
                string Bus_name[m];
                string Bus_code[m];
                string Bus_type[m];

                string Truck_code[m];
                int toll_truck[m];
                int fine[m];
                string Banned_code[m];
                int allowed_wgt[m];
                int banned_wgt[m];


                string byke_model[m];
                string byke_name[m];
                int toll_byke[m];


                string Car_brand[m];
                string Car_model[m];
                int toll_car[m];

                string Pickup_name[m];
                string Pickup_model[m];
                int toll_pickup[m];

                int totalVehicle=0;

public:
                void CNT();

                void enterBus();
                void enterTruck();
                void enterByke();
                void enterCar();
                void enterPicup();

                void display();
                void banned_vehicle();
                void totalamount();
                void totalvehicle();

                void print();
};
    void Toll_Plaza::print()
            {
                cout<<"=============================================================================================\n";
            }

    void Toll_Plaza::CNT()
            {
                buscount = 0, allowed_truckcount=0,banned_truckcount=0, bykecount=0, carcount=0, pickupcount=0;
            }
    void Toll_Plaza::enterBus()
            {
                cout<<"Enter Bus Name : ";
                string name;
                cin>>name;
                {
                    Bus_name[buscount] = name;
                }
                   string code;
                    cout<<"Enter bus code : ";
                     cin >> code;
                    {
                                    Bus_code[buscount] = code;
                    }
                    cout<<" Press => 1 for Long route \n\t=> 2 for Local \n";
                    char a;
                    cin>>a;
                    if(a== '1' )
                    {
                                    cout<<"\nToll of this BUS  = 2000 BDT. Please Collect it...\n";
                                      toll_bus[buscount] = 2000;
                                      Bus_type[buscount] = "Long route";
                                        buscount++;
                                        totalVehicle++;

                    }
                    else if(a== '2'){
                                   cout<<"\nToll of this BUS  = 1000 BDT. Please Collect it...\n";
                                      toll_bus[buscount] = 1000;
                                       Bus_type[buscount] = "Local";
                                        buscount++;
                                         totalVehicle++;

                }
            else{
                                    cout<<"Wrong input....\n";
            }

    }
void Toll_Plaza::enterTruck()
    {
        cout<<"Check the weight of truck and input (in TON) : ";
        int weight;
        cin>>weight;

        string code;
        cout<<"Enter truck code : ";
        cin>>code;

       if(weight<=50)
       {
                        cout<<"\nToll of this truck = 2500 BDT. Please collect this.....\n";
                        toll_truck[allowed_truckcount] = 2500;
                        Truck_code[allowed_truckcount] = code;
                        allowed_wgt[allowed_truckcount] = weight;
                        allowed_truckcount++;
                         totalVehicle++;

       }
       else
       {
                       cout<<"\nTruck is overloaded ( more than 50 TON) ....  It shold be banned........  \nFine = 5000 BDT\n";
                       Banned_code[banned_truckcount] = code;
                       fine[banned_truckcount] = 5000;
                       banned_wgt[banned_truckcount] = weight;
                        banned_truckcount++;
        }

  }
void Toll_Plaza::enterByke()
    {
            string brand;
            cout<<"Enter byke Brand : ";
            cin>>brand;
            {
                    byke_name[bykecount] = brand;
            }
            string model;
            cout<<"Enter byke model : ";
            cin>>model;
            {
                byke_model[bykecount] = model;
            }

            cout<<"\nToll of this byke is :  500 BDT............. Please collect it.........."<<endl;
            toll_byke[bykecount] = 500;
            bykecount++;
            totalVehicle++;

    }
void Toll_Plaza::enterCar()
    {

           string brand;
            cout<<"Enter Car Brand : ";
            cin>>brand;
            {
                           Car_brand[carcount] = brand;
            }
            string model;
            cout<<"Enter car model : ";
            cin>>model;
            {
                            Car_model[carcount] = model;
            }
            cout<<"\nToll of this Car is 800 BDT..... Please collect it..........\n";
            toll_car[carcount] = 800;
            carcount++;
             totalVehicle++;

    }
void Toll_Plaza::enterPicup()
    {
           cout<<"Enter Brand : ";
          string brand;
           cin>>brand;
           {
                           Pickup_name[pickupcount] = brand;
           }
           cout<<"Enter model : ";
           string model;
           cin>>model;
           {
                           Pickup_model[pickupcount]= model;
           }
           cout<<"\nToll of this Pickup is  700 BDT.....Please collect it ........\n";
           toll_pickup[pickupcount]= 700;
           pickupcount++;
           totalVehicle++;

    }
void Toll_Plaza::display()
    {

        if(buscount ==0)
            {
                cout<<"No bus entered...........\n";
            }
        else
        {
                cout<<"\nEntered busses ..............\n";
                print();
                for(int i= 0; i<buscount; i++)
                {
                    cout<<i+1<<" . Bus Name : "<<Bus_name[i]<<"\t"<<"Bus Code : "<<Bus_code[i]<<"\t"<<"Bus Type :  "<<Bus_type[i]<<"\t"<< " Toll amount : "<<   toll_bus[i]<<endl;
                    print();
                }
            cout<<"Total Entered Busses : "<<buscount<<endl;
        }

        if(allowed_truckcount == 0)
            {
                cout<<"\nNo truck entered ........\n";
            }
     else
        {
            cout<<"\nEnter trucks ............\n";
            int sum = 0;
             print();
            for(int i = 0; i<allowed_truckcount; i++)
            {
                            cout<<i+1<<" . Truck code : "<< Truck_code[i]<<"\t"<<"Weight  (ton): "<<allowed_wgt[i]<<"\t"<<"Toll amount : "<<toll_truck[i]<<endl;
                            sum = sum + toll_truck[i];
                            print();
            }
            cout<<"\nTotal entered truck : "<< allowed_truckcount<<endl;
            cout<<"\nTotal toll of truck : "<<sum<<endl;

        }
     if(bykecount == 0)
             {
                 cout<<"\nNo byke Entered.......... \n";
             }
     else
        {
            cout<<"\nEntered Bykes ............."<<endl;
            int sum = 0;
            print();
            for(int i = 0; i<bykecount; i++)
            {
                            cout<<i+1<<" . Brand : "<<byke_name[i]<<"\t"<<"Byke model : "<<byke_model[i]<<"\t"<<"Toll amount : "<<toll_byke[i]<<endl;
                            sum = sum + toll_byke[i];
                            print();
            }
            cout<<"\nTotal entered Byke : "<<bykecount<<endl;
            cout<<"\nTotal toll of byke : "<<sum<<endl<<endl;
        }
      if(carcount == 0)
            {
                cout<<"\nNo car entered...........\n";
            }
        else
        {
            cout<<"\nEntered Cars...............\n";

            int sum = 0;
            print();
            for(int i = 0; i<carcount; i++)
            {
                cout<<i+1<<" . Brand : "<<Car_brand[i]<<"\t"<<"Model : "<<Car_model[i]<<"\t"<<"Toll Amount : "<<toll_car[i]<<endl;
                sum = sum + toll_car[i];
                print();
            }
            cout<<"\nTotal entered CAR : "<<carcount<<endl;
            cout<<"\nTotal toll of Car : "<<sum<<endl<<endl;
        }
        if(pickupcount==0)
            {
                cout<<"\nNo pickup entered........\n";
            }
        else
        {
            cout<<"\nEntered Pickups.............\n";

            int sum = 0;
            print();
            for(int i = 0; i<pickupcount; i++)
            {
                            cout<<i+1<<" . Brand : "<<Pickup_name[i]<<"\t"<<"Model : "<<Pickup_model[i]<<"\t"<<"Toll amount : "<<toll_pickup[i]<<endl;
                            sum = sum + toll_pickup[i];
                            print();
            }
            cout<<"\nTotal Entered Picup : "<<pickupcount<<endl;
            cout<<"Total toll of Pickup : "<<sum<<endl<<endl;
        }

    }
void Toll_Plaza::banned_vehicle()
    {
          int sum = 0;
          print();
        for(int i= 0; i<banned_truckcount; i++)
        {
                        cout<<i+1<<" . Truck Code : "<<Banned_code[i]<<"\tWeight :  "<<banned_wgt[i]<<endl;
                        sum = sum + fine[i];
                        print();
        }
        cout<<"Total Banned trucks : "<<banned_truckcount<<endl;

        cout<<"Total collected fine : "<<sum<<" (5000) per truck"<<endl;
    }
void Toll_Plaza::totalamount()
    {
            int sum=0;
            for(int i=0; i<buscount; i++)
            {
                            sum = sum + toll_bus[i];
            }
             for(int i=0; i<allowed_truckcount; i++)
            {
                            sum = sum + toll_truck[i];
            }
              for(int i=0; i<bykecount; i++)
            {
                            sum = sum + toll_byke[i];
            }
                  for(int i=0; i<carcount; i++)
            {
                            sum = sum + toll_car[i];
            }
              for(int i=0; i<pickupcount; i++)
            {
                            sum = sum + toll_pickup[i];
            }
            cout<<"Total collected amount = "<<sum<<" BDT"<<endl;
    }
void Toll_Plaza::totalvehicle()
    {
        cout<<"\nTotal entered Vehicle : "<<totalVehicle<<endl;
    }


int main()
{
            Toll_Plaza jamuna;

            jamuna.CNT();

            char xxx;

            do
            {
                cout<<"\n\nEnter\n\n 1 to select entering vehicle\n 2 to show  banned TRUCKS\n 3 to show  of entered vehicle lists and costs\n 4 to show total amount(without fine)\n 5 to show number of entered vehicle\n 6 to quit database.\n\n";

                cout<<"Select : ";
                cin>>xxx;
                 switch(xxx)
                 {
                     case '1':
                                     cout<<"Enter \n  a for bus\n  b for truck\n  c for byke\n  d for CAR\n  e for PICKUP\n\n";
                                     char x;
                                     cout<<"Select :  ";
                                     cin>>x;
                                     switch(x)
                                     {
                                     case 'a':
                                                    jamuna.enterBus();
                                                    break;
                                     case 'b':
                                                     jamuna.enterTruck();
                                                    break;
                                     case 'c':
                                                    jamuna.enterByke();
                                                    break;
                                     case 'd':
                                                    jamuna.enterCar();
                                                    break;
                                     case 'e':
                                                    jamuna.enterPicup();
                                                    break;
                                     default:
                                                    cout<<"Wrong Input...\n";
                                                    break;
                                     }

                                     break;
                    case '2':
                                    jamuna.banned_vehicle();
                                    break;
                    case '3':
                                    jamuna.display();
                                    break;
                    case '4':
                                    jamuna.totalamount();
                                    break;
                    case '5':
                                    jamuna.totalvehicle();
                                    break;
                    case '6':
                                    cout<<"\nProgram terminated............\n";
                                    return 0;
                    default:
                                     break;

                 }
        }
        while(1);


        return 0;
}

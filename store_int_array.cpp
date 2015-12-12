
/************************************************************************
                                                                        *
                                                                        *
this a demonstration for the algorithm to store the value in the array  *
                                                                        *
*************************************************************************/
#include<iostream>

using namespace std;

int main()


{
    int k=0;
    struct Path
{   double time;
    double x , y, z;
    double psi, theta, phi;
};

    Path allpath[7]={0,0,0,0,0,0,0};
double time_array[7]={0},
       x_array[7]={0},
       y_array[7]={0},
       z_array[7]={0},
       psi_array[7]={0},
       theta_array[7]={0},
       phi_array[7]={0};
   double data_collect[7][7]={{1,1,1,1,1,1,1},
                              {2,2,2,2,2,2,2},
                              {3,3,3,3,3,3,3},
                              {4,4,4,4,4,4,4},
                              {5,5,5,5,5,5,5},
                              {6,6,6,6,6,6,6},
                              {7,7,7,7,7,7,7}};


    for(int i=0;i<7;i++)
     {
         for(int j=0;j<7;j++)
         {
             switch(j)
             {
                       case 0:time_array[k]=data_collect[i][j];break;
                       case 1:x_array[k]=data_collect[i][j];break;
                       case 2:y_array[k]=data_collect[i][j];break;
                       case 3:z_array[k]=data_collect[i][j];break;

                       case 4:psi_array[k]=data_collect[i][j];break;
                       case 5:theta_array[k]=data_collect[i][j];break;
                       case 6:phi_array[k]=data_collect[i][j];break;
                       }
          }

      k++;

     }


    for(int i=0;i<7;i++)
    {allpath[i].time=time_array[i];
     allpath[i].x=x_array[i];
     allpath[i].y=y_array[i];
     allpath[i].z=z_array[i];
     allpath[i].psi=psi_array[i];
     allpath[i].theta=theta_array[i];
     allpath[i].phi=phi_array[i];
     //allpath[i]={time_array[i],x_array[i],y_array[i],z_array[i],psi_array[i],theta_array[i],phi_array[i]};

     cout<<"path"<<i<<endl<<allpath[i].x<<"\t"<<allpath[i].y<<"\t"<<allpath[i].z<<"\t"<<allpath[i].psi<<"\t"<<allpath[i].theta<<"\t"<<allpath[i].phi<<"\t"<<endl;



    }

cout<<endl<<endl<<"the struct: "<<sizeof(allpath)*300<<endl<<"the single value: "<<sizeof(data_collect);
   return 0;
}





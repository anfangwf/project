#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtGui>
#include <QtWidgets>

#include<QString>
// path struct which can be transmitted to the ads
struct Path
{   double time;
    double x , y, z;
    double psi, theta, phi;
};

/*Path *path1=new Path,
     *path2=new Path,
     *path3=new Path,
     *path4=new Path,
     *path5=new Path,
     *path6=new Path,
     *path7=new Path;
*/
//initialization
Path allpath[7]={0,0,0,0,0,0,0};
double time_array[7]={0},
       x_array[7]={0},
       y_array[7]={0},
       z_array[7]={0},
       psi_array[7]={0},
       theta_array[7]={0},
       phi_array[7]={0};


double data_collect[7][7]={0.0};




//to determine if all paths are ok
bool allpath_ok=true;

//to assume the orginal position







/*double x_0=0,y_0=0,z_0=0.5,
       psi_0=0,theta_0=0,
       phi_0=0;
*/




MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //set length of the column
    for(int i=0;i<7;i++)
    {
    ui->tableWidget->setColumnWidth(i,65);
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_pushButton_clicked()
{
    QString file_full;
    //get file address
    file_full = QFileDialog::getOpenFileName(this,tr("open file"),".",tr("Text Files(*.txt)"));

    QFile file(file_full);
    //read file
    if(file.open(QIODevice::ReadOnly))
    {
        QTextStream read(&file);
        for(int i=0;i<29;i++)
        {
            read.readLine();
        }

        qint64 _line=10; //line length

        for(int j=0;j<7;j++)//row
        {
            for(int i=0;i<7;i++)//column
            {
            QString x1=read.readLine(_line);
            x1=x1.simplified();
            data_collect[i][j]=x1.toDouble();

            QTableWidgetItem *item0;

            item0=new QTableWidgetItem;
            item0->setText(x1);
            ui->tableWidget->setItem(j,i,item0);
            }
            read.readLine();
        }
    }
//stroe the value as array by struct and is demonstrated in the separately program "store_in_arry"
     int k=0;
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

    }

}





    /*  for (int i=1;i<7;i++)

 //insert value to the paths
  path1->x=data_collect[0][1];
    path2->x=data_collect[1][1];
    path3->x=data_collect[2][1];
    path4->x=data_collect[3][1];
    path5->x=data_collect[4][1];
    path6->x=data_collect[5][1];
    path7->x=data_collect[6][1];


    path1->y=data_collect[0][2];
    path2->y=data_collect[1][2];
    path3->y=data_collect[2][2];
    path4->y=data_collect[3][2];
    path5->y=data_collect[4][2];
    path6->y=data_collect[5][2];
    path7->y=data_collect[6][2];


    path1->z=data_collect[0][3];
    path2->z=data_collect[1][3];
    path3->z=data_collect[2][3];
    path4->z=data_collect[3][3];
    path5->z=data_collect[4][3];
    path6->z=data_collect[5][3];
    path7->z=data_collect[6][3];

    path1->psi=data_collect[0][4];
    path2->psi=data_collect[1][4];
    path3->psi=data_collect[2][4];
    path4->psi=data_collect[2][4];
    path5->psi=data_collect[4][4];
    path6->psi=data_collect[5][4];
    path7->psi=data_collect[6][4];

    path1->theta=data_collect[0][5];
    path2->theta=data_collect[1][5];
    path3->theta=data_collect[2][5];
    path4->theta=data_collect[3][5];
    path5->theta=data_collect[4][5];
    path6->theta=data_collect[5][5];
    path7->theta=data_collect[6][5];

    path1->phi=data_collect[0][6];
    path2->phi=data_collect[1][6];
    path3->phi=data_collect[2][6];
    path4->phi=data_collect[2][6];
    path5->phi=data_collect[4][6];
    path6->phi=data_collect[5][6];
    path7->phi=data_collect[6][6];
*/




// check the path
    void MainWindow::on_checkBtn_clicked()
    {

      for (int i=0;i<7;i++)
      {

          //to determine if these elements are ok or overranged

          bool x_ok=true,y_ok=true,z_ok=true,
                    psi_ok=true,theta_ok=true,
                    phi_ok=true;

          QString x_part ="",
                  y_part="",
                  z_part="",
                  psi_part="",
                  theta_part="",
                  phi_part="";



          int ok_sum=0;  //check which part is ok
          for(int j=1;j<7;j++)
          {

              switch(j)
              {
              case 1:if((-0.5<data_collect[i][1]) and (data_collect[i][1]<0.5))
                        {x_ok=false;
                         ok_sum++;
                        }break;
              case 2:if((-0.5<data_collect[i][2]) and (data_collect[i][2]<0.5))
                        {y_ok=false;
                         ok_sum++;
                        }break;
              case 3:if((0.25<data_collect[i][3]) and (data_collect[i][3]<0.95))
                        {z_ok=false;
                          ok_sum++;
                        }break;

              case 4:if((-20<data_collect[i][4]) and (data_collect[i][4]<20))
                        {psi_ok=false;
                           ok_sum++;
                        }break;
              case 5:if((-20<data_collect[i][5]) and (data_collect[i][5]<20))
                        {theta_ok=false;
                          ok_sum++;
                        }break;
              case 6:if((-20<data_collect[i][6]) and (data_collect[i][6]<20))
                        {phi_ok=false;
                          ok_sum++;
                        }break;

                }
            }



           if(x_ok||y_ok||z_ok||phi_ok||theta_ok||psi_ok)

              {if(x_ok)
                   x_part="x direction,";
               if(y_ok)
                   y_part="y direction,";
               if(z_ok)
                   z_part="z dirction,";
               if(psi_ok)
                   psi_part="psi angle,";
               if(theta_ok)
                   theta_part="theta angle,";
               if(psi_ok)
                   psi_part="phi angle,";

                 QString over_part=x_part+y_part+z_part+psi_part+theta_part+phi_part;
                 QString path_num_string=QString("%1").arg(i+1); //from int to string
                 QString over_num_string=QString("%1").arg(6-ok_sum);
                 QString warning_string="The path"+path_num_string+" has "+over_num_string+"("+over_part+")"+" overranged term(s).\n ";
                 QMessageBox::warning(this,tr("Warning"),warning_string);
                 allpath_ok=false;
              }

       }

           if(allpath_ok)
           QMessageBox::information(this,tr("Information"),tr("All paths are OK"));

    }

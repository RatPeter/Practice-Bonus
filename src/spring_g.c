#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <gsl/gsl_fit.h>

int main()
{
    char tar[10000];      //从文件中读取数据
    double cur_lib[1000];
    char *ch;
	  int cur_count = 0;
    FILE * fp = fopen("./data/spring_data.csv", "r");
    while(fgets(tar, 10000, fp)!=NULL)
	{
        ch = strtok(tar, ",");  
        while(ch!=NULL)
		{
            cur_lib[cur_count] = atof(ch);
            ch = strtok(NULL, ",");
            cur_count++;
        }
    }
    fclose(fp);

    int n=cur_count/2-1;
	  double x[n];
	  double y[n];
	  for (int i=0;i<n;i++)
	  {
		y[i]=cur_lib[i*2+2];
		x[i]=cur_lib[i*2+3]*9.81;
	  }

    double c0, c1, cov00, cov01, cov11, sumsq;

    gsl_fit_linear (x, 1, y, 1, n,                            //使用GSL对数据进行线性回归
                   &c0, &c1, &cov00, &cov01, &cov11,
                   &sumsq);

    printf ("best fit: Y = %g + %g X\n", c0, c1);
    printf ("covariance matrix:\n");
    printf ("[ %g, %g\n  %g, %g]\n",
          cov00, cov01, cov01, cov11);
    printf ("sumsq = %g\n", sumsq);

    printf ("\n");

    FILE *pipe = popen("gnuplot -persist", "w");  // 使用Gnuplot实现数据可视化

    if (pipe) {   // If gnuplot is found
      fprintf(pipe, "set term wx\n");         // set the terminal               
      fprintf(pipe, "set datafile separator ','\n"); //datafile separator ','
      fprintf(pipe, "set xlabel '|Force| (Newtons)'\n");
      fprintf(pipe, "set ylabel 'Distance (meters)'\n");
      fprintf(pipe, "set title '<X,Y> and Linear fit:y=%.4f*x+%.4f'\n",c1,c0);
      fprintf(pipe, "plot './data/spring_data.csv' using  ($2*9.81):1 title '(Force,Distance)',%g + %g*x, \n",c0,c1);
      
      fflush(pipe); //flush pipe
      fprintf(pipe,"exit \n");   // exit gnuplot
      pclose(pipe);    //close pipe
    }
    return 0;
};
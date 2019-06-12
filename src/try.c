#include <stdio.h>

int main(void)
{

    FILE *pipe = popen("gnuplot -persist", "w");  // Open a pipe to gnuplot

    if (pipe) {   // If gnuplot is found
      fprintf(pipe, "d(x) = (1/k)*x\n");
      fprintf(pipe, "set datafile separator ','\n");
      fprintf(pipe, "fit d(x) './spring_data.csv' using ($2*9.81):1 via k\n");
      fprintf(pipe, "set term wx\n");         // set the terminal               
      fprintf(pipe, "set datafile separator ','\n"); //datafile separator ','
      fprintf(pipe, "set xlabel '|Force| (Newtons)'\n");
      fprintf(pipe, "set ylabel 'Distance (meters)'\n");
      fprintf(pipe, "set title 'Measured Displacement of Spring'\n");
      fprintf(pipe, "plot './spring_data.csv' using  ($2*9.81):1 title '(Force,Distance)',\
     './spring_data.csv' using ($2*9.81):(d($2*9.81)) title '',\
     './spring_data.csv' using ($2*9.81):(d($2*9.81))  title 'Force=f(Distance)' with line ls 12\n");
      
      fflush(pipe); //flush pipe
      fprintf(pipe,"exit \n");   // exit gnuplot
      pclose(pipe);    //close pipe
    }
    return 0;
};
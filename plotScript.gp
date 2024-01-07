# plot_script.gnu

# Check if command-line arguments are provided
if (ARGC != 5) {
    print "Usage: gnuplot -c plot_script.gnu <filename> <x_column> <y_column> <y_label> <plot_title>"
    exit 1
}

filename = ARG1
x_column = ARG2
y_column = ARG3
y_label = ARG4
plot_title = ARG5

set datafile separator ","
set timefmt "%Y-%m-%d %H:%M:%S"
set xdata time
set format x "%Y-%m-%d\n%H:%M:%S"
set xlabel "Date and Time"
set ylabel y_label
set title plot_title
set xtics font "default,7"
plot filename using int(x_column):int(y_column) with lines title "Data Points"

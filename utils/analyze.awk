#!/usr/bin/awk
# @brief: extract fps and elpased time; calculate average of them

BEGIN {   
    i = 1
    sumFPS = 0
    sumElapsed = 0
}

{
    if (FNR == (5 * i - 2))  {
        frames = $4
    } 

    if (FNR == (5 * i - 1))  {
        # print FNR, $4
        sumElapsed += $4
    }  

    if (FNR == (5 * i)) {
        # print FNR, $4
        sumFPS += $4
        ++i
    }
        
}


END {
    # print i - 1
    print "Frames          : ", frames
    print "Avg FPS         : ", sumFPS / (i - 1)
    print "Avg Elapsed Time: ", sumElapsed / (i - 1)
}

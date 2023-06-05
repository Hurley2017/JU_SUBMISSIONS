    #! bin/bash
    home_dir=${pwd}
    Operating_System_Types=$(uname)
    Version=$(uname -a)
    Release_Number=$(uname -r)
    Kernel_Version=$(uname -v)
    Current_Path_Settings=$(ls -l $home_dir)
    echo "Home Directory: $home_dir"
    echo "Operating System Type: $Operating_System_Types"
    echo "Version: $Version"
    echo "Release Number: $Release_Number"
    echo "Kernel Version: $Kernel_Version"
    echo "Current Path Settings: $Current_Path_Settings"
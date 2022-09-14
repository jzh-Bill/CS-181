
#include <stdio.h>
#define MAX_CLASS_NAME 16
#define MAX_LOCATION_NAME 24
#define MAX_CLASSES 100

int main()
{
    typedef struct class_info
    {
        char class[MAX_CLASS_NAME];
        char location[MAX_LOCATION_NAME];
        unsigned int enrollment;
    } class_info_t;

    class_info_t class_list[MAX_CLASSES];
    int n_classes = 0;

    char tem_name[16];
    char tem_location[24];
    int tem_enrollment;

    FILE *fp;

    int N = 50;

    char str[N - 1];

    char delims[] = {"::"};

    int index = 0;

    if ( (fp = fopen("file.txt", "r")) == NULL )
    {
        printf("Fail to open file!");
    }

    while( fgets(str, N - 1, fp) != NULL )
    {
         class_list[index].class = strtok(str, delims);
         class_list[index].location =strtok(str, delims);
         class_list[index].enrollment = fp*;
    }

}

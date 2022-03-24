#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

typedef struct lotto_record_t {
    int lotto_num ;
    float lotto_receipt;
    int emp_id;
    char lotto_date[16];
    char lotto_time[16];
}lotto_record_t;

void print_vorform(FILE* freport) {
    fprintf(freport, "========= lotto694 Report =========\n");
    fprintf(freport, "- Date ------ Num. ------ Receipt -\n");
}

int print_form (FILE* freport ,lotto_record_t day_report, int num) { 
    fprintf(freport, "%s     %d/%d     %d\n", day_report.lotto_date,
                                     num,
                                     (int)day_report.lotto_receipt/55,
                                     (int)day_report.lotto_receipt);
    return ((int)day_report.lotto_receipt/55);
}

int print_nachform (FILE* freport, int alldate_num ,int all_row_num ,int all_reciept_num ,int all_price_num) {
    time_t curtime = time (0);
    char curtime_array[100];
    fprintf(freport, "-----------------------------------\n");
    strftime (curtime_array, 100, "%Y%m%d", localtime(&curtime));
    fprintf(freport,"        %d    %d/%d    %d\n", alldate_num-1, all_row_num ,all_reciept_num, all_price_num);
    fprintf(freport, "======== %s Printed ========\n", curtime_array);
    
}

int main() {
    FILE* fp;
    FILE* freport;
    fp = fopen("records.txt", "rb");
    freport = fopen("report.bin", "w+");
    int result = 0, times = 0 , num = 1, plus = 0;
    int alldate_num = 1, all_row_num =0, all_reciept_num = 1; 
    float all_price_num = 0.0;
    lotto_record_t records;
    lotto_record_t day_report;
    print_vorform(freport);
    while (fread(&records, sizeof(records), 1, fp)) {
        result = strcmp(day_report.lotto_date, records.lotto_date);
        if (result == 0) {
            day_report.lotto_receipt += records.lotto_receipt;
            day_report.lotto_num += records.lotto_num;
            all_reciept_num += (records.lotto_num);
            num++;
        } else {
            times > 0 ? print_form(freport, day_report, num) : 1;
            strcpy (day_report.lotto_date, records.lotto_date);
            day_report.lotto_num = records.lotto_receipt;
            all_reciept_num += (records.lotto_num);
            day_report.lotto_receipt = records.lotto_receipt;
            alldate_num++;
            times ++;
            all_row_num += num;
            num = 1;
        }
        if (fread(&records, sizeof(records), 1, fp) == NULL ) {
            all_row_num += num;
            plus = print_form(freport, day_report, ++num);
            fseek(fp, sizeof(records), SEEK_SET);
        } else {
            plus = 0;
        }
    }
    all_price_num = all_reciept_num * 55;
    print_nachform(freport, alldate_num, all_row_num, all_reciept_num, (int)all_price_num);
    fclose(freport);
    fclose(fp);
    return 0;

}
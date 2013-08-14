#include <db.h>

void init() {

    DB *dbp;
    int ret;
    char *program_name = "kiev-init";
    char *file_name = "kiev-0531.db";

    /* Variable assignments omitted for brevity */

    /* Initialize the DB handle */
    ret = db_create(&dbp, NULL, 0);
    if (ret != 0) {
        return;
    }

    /*
     * Configure the database for sorted duplicates
    */ 
    ret = dbp->set_flags(dbp, DB_DUP);
    if (ret != 0) {
        printf("shit.%d\n", ret);
        return;
    }
    
    printf("ready_to_open\n");
    /* Now open the database */
    ret = dbp->open(dbp,        /* Pointer to the database */
                    NULL,       /* Txn pointer */
                    file_name,  /* File name */
                    NULL,       /* Logical db name (unneeded) */
                    DB_HASH,   /* Database type (using btree) */
                    DB_CREATE,  /* Open flags */
                    0);         /* File mode. Using defaults */
    if (ret != 0) {
        dbp->close(dbp, 0);
        return(ret);
    } 

}

int main(void) {
    init();
}
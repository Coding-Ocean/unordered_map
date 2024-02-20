#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// ハッシュテーブルのエントリ
typedef struct entry {
    char* key;
    int value;
    struct entry* next;
} entry_t;

// ハッシュテーブル
typedef struct hashtable {
    int size;
    entry_t** entries;
} hashtable_t;

// ハッシュ関数
unsigned int hash(const char* key) {
    unsigned int hashval = 0;
    while (*key) {
        hashval = (hashval * 127) + *key++;
    }
    return hashval;
}

// ハッシュテーブルの初期化
hashtable_t* hashtable_init(int size) {
    hashtable_t* ht = (hashtable_t*)malloc(sizeof(hashtable_t));
    ht->size = size;
    ht->entries = (entry_t**)malloc(sizeof(entry_t*) * size);
    for (int i = 0; i < size; i++) {
        ht->entries[i] = NULL;
    }
    return ht;
}

// ハッシュテーブルに値を挿入
void hashtable_insert(hashtable_t* ht, const char* key, int value) {
    unsigned int hashval = hash(key) % ht->size;
    entry_t* new_entry = (entry_t*)malloc(sizeof(entry_t));
    new_entry->key = _strdup(key);
    new_entry->value = value;
    new_entry->next = ht->entries[hashval];
    ht->entries[hashval] = new_entry;
}

// ハッシュテーブルから値を検索
int hashtable_get(hashtable_t* ht, const char* key) {
    unsigned int hashval = hash(key) % ht->size;
    entry_t* entry = ht->entries[hashval];
    while (entry != NULL) {
        if (strcmp(entry->key, key) == 0) {
            return entry->value;
        }
        entry = entry->next;
    }
    return -1;
}

// ハッシュテーブルから値を削除
void hashtable_delete(hashtable_t* ht, const char* key) {
    unsigned int hashval = hash(key) % ht->size;
    entry_t* prev = NULL;
    entry_t* entry = ht->entries[hashval];
    while (entry != NULL) {
        if (strcmp(entry->key, key) == 0) {
            if (prev == NULL) {
                ht->entries[hashval] = entry->next;
            }
            else {
                prev->next = entry->next;
            }
            free(entry->key);
            free(entry);
            return;
        }
        prev = entry;
        entry = entry->next;
    }
}

// ハッシュテーブルの破棄
void hashtable_destroy(hashtable_t* ht) {
    for (int i = 0; i < ht->size; i++) {
        entry_t* entry = ht->entries[i];
        while (entry != NULL) {
            entry_t* next = entry->next;
            free(entry->key);
            free(entry);
            entry = next;
        }
    }
    free(ht->entries);
    free(ht);
}

int main() {
    hashtable_t* ht = hashtable_init(10);

    hashtable_insert(ht, "餃子", 100);
    hashtable_insert(ht, "ラーメン", 200);
    hashtable_insert(ht, "チャーハン", 300);

    printf("餃子: %d\n", hashtable_get(ht, "餃子"));
    printf("ラーメン: %d\n", hashtable_get(ht, "ラーメン"));
    printf("チャーハン: %d\n", hashtable_get(ht, "チャーハン"));

    hashtable_delete(ht, "ラーメン");
    printf("\nラーメン: deleted\n");

    int val = hashtable_get(ht, "ラーメン");
    if (val == -1)
        printf("ラーメン: not found\n");
    else
        printf("ラーメン: %d\n", val);

    hashtable_destroy(ht);

    system("pause>0");
    return 0;
}

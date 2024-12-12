#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>

// Struct definition
typedef struct line_head {
    int fd;                    // File descriptor
    int bytes;                 // Bytes read
    char *buffer;              // Pointer to buffer
    struct line_head *next;    // Pointer to the next node
} line_head;

// Find a node in the list by file descriptor
line_head *find_or_create_node(line_head **head, int fd) {
    line_head *current = *head;

    // Search for the node
    while (current) {
        if (current->fd == fd) {
            return current;
        }
        current = current->next;
    }

    // If not found, create a new node
    line_head *new_node = malloc(sizeof(line_head));
    if (!new_node) return NULL;

    new_node->fd = fd;
    new_node->bytes = 0;
    new_node->buffer = NULL;
    new_node->next = *head;
    *head = new_node;

    return new_node;
}

int main() {
    line_head *head = NULL; // Initialize linked list

    // Open two files
    int fd1 = open("file1.txt", O_RDONLY);
    int fd2 = open("file2.txt", O_RDONLY);

    if (fd1 == -1 || fd2 == -1) {
        perror("Failed to open files");
        return 1;
    }

    // Get or create nodes for the file descriptors
    line_head *node1 = find_or_create_node(&head, fd1);
    line_head *node2 = find_or_create_node(&head, fd2);

    // Read data from file1 (fd1)
    char buffer1[128];
    ssize_t bytes1 = read(fd1, buffer1, sizeof(buffer1));
    if (bytes1 > 0) {
        buffer1[bytes1] = '\0';
        node1->buffer = strdup(buffer1);
        node1->bytes = bytes1;
        printf("Data from fd1: %s\n", node1->buffer);
    }

    // Read data from file2 (fd2)
    char buffer2[128];
    ssize_t bytes2 = read(fd2, buffer2, sizeof(buffer2));
    if (bytes2 > 0) {
        buffer2[bytes2] = '\0';
        node2->buffer = strdup(buffer2);
        node2->bytes = bytes2;
        printf("Data from fd2: %s\n", node2->buffer);
    }

    // Cleanup
    close(fd1);
    close(fd2);
    while (head) {
        line_head *tmp = head;
        head = head->next;
        free(tmp->buffer);
        free(tmp);
    }

    return 0;
}

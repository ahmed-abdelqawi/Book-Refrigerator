# input_generator.py

num_books = 1000

with open("input.txt", "w") as f:
    for i in range(1, num_books + 1):
        f.write(f"Title: Book Title {i}\n")
        f.write(f"Writer: Writer Name {i}\n")
        f.write(f"Category: Category {i}\n")
        f.write(f"Year: {2000 + (i % 25)}\n")
        f.write("\n")

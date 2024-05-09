## Outline Wizard

This C++ program allows users to create, organize, and store documents in a hierarchical outline format. Users can add titles, sections, subsections, and sub-subsections to their documents, and then view or save the document outline or full document content.

### Features
- **Insert Title:** Add a title to the document.
- **Insert Sections:** Add sections to the document.
- **Insert Subsections:** Add subsections to the sections.
- **Insert Sub-Subsections:** Add sub-subsections to the subsections.
- **Display Document Outline:** View the hierarchical outline of the document.
- **Display Document:** View the full content of the document.
- **Save Document:** Save the document to a file.

### How to Use
1. Run the program and enter the number of documents you want to create.
2. For each document, follow the on-screen menu to add titles, sections, subsections, and sub-subsections.
3. Use the menu to view or save the document outline or full document content.

### Example
```
How many documents would you like to add?
1

1] INSERT DOCUMENT TITLE
2] INSERT SECTIONS OF THE DOCUMENT
3] INSERT SUBSECTIONS OF THE DOCUMENT
4] INSERT SUBSECTIONS OF THE SUBSECTIONS OF THE DOCUMENT
5] DISPLAY DOCUMENT OUTLINE
6] DISPLAY DOCUMENT
7] SAVE
8] EXIT

Enter your choice: 1
Enter Title: Introduction
Enter Info: This is the introduction section.

1] INSERT DOCUMENT TITLE
2] INSERT SECTIONS OF THE DOCUMENT
3] INSERT SUBSECTIONS OF THE DOCUMENT
4] INSERT SUBSECTIONS OF THE SUBSECTIONS OF THE DOCUMENT
5] DISPLAY DOCUMENT OUTLINE
6] DISPLAY DOCUMENT
7] SAVE
8] EXIT

Enter your choice: 2
Enter section: Section 1
Enter Info for Section 1: This is section 1.

1] INSERT DOCUMENT TITLE
2] INSERT SECTIONS OF THE DOCUMENT
3] INSERT SUBSECTIONS OF THE DOCUMENT
4] INSERT SUBSECTIONS OF THE SUBSECTIONS OF THE DOCUMENT
5] DISPLAY DOCUMENT OUTLINE
6] DISPLAY DOCUMENT
7] SAVE
8] EXIT

Enter your choice: 3
Enter section to which you want to add subsection: Section 1
How many subsections do you want to add? 2
Enter sub-section 1: Subsection 1
Enter Info for Subsection 1: This is subsection 1.
Enter sub-section 2: Subsection 2
Enter Info for Subsection 2: This is subsection 2.

1] INSERT DOCUMENT TITLE
2] INSERT SECTIONS OF THE DOCUMENT
3] INSERT SUBSECTIONS OF THE DOCUMENT
4] INSERT SUBSECTIONS OF THE SUBSECTIONS OF THE DOCUMENT
5] DISPLAY DOCUMENT OUTLINE
6] DISPLAY DOCUMENT
7] SAVE
8] EXIT

Enter your choice: 5
TITLE: Introduction
    SECTION: Section 1
        SUBSECTION: Subsection 1
        SUBSECTION: Subsection 2

1] INSERT DOCUMENT TITLE
2] INSERT SECTIONS OF THE DOCUMENT
3] INSERT SUBSECTIONS OF THE DOCUMENT
4] INSERT SUBSECTIONS OF THE SUBSECTIONS OF THE DOCUMENT
5] DISPLAY DOCUMENT OUTLINE
6] DISPLAY DOCUMENT
7] SAVE
8] EXIT

Enter your choice: 7
Document saved successfully.

```

### Note
- The program uses a tree data structure to represent the document outline.
- Each node in the tree represents a title, section, subsection, or sub-subsection.
- Nodes are linked together to form the hierarchical structure of the document.

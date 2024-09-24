input_data = """
(((RectangleX1 1) 15)
 ((RectangleX2 1) 4) 
 ((RectangleY1 1) 6)
 ((RectangleY2 1) 5)
 ((RectangleX1 2) 8)
 ((RectangleX2 2) 6)
 ((RectangleY1 2) 6)
 ((RectangleY2 2) 4)
 ((RectangleX1 3) 0)
 ((RectangleX2 3) 5)
 ((RectangleY1 3) 9)
 ((RectangleY2 3) 21)
 ((RectangleX1 4) 15)
 ((RectangleX2 4) 9)
 ((RectangleY1 4) 24)
 ((RectangleY2 4) 6)
 ((RectangleX1 5) 22)
 ((RectangleX2 5) 8)
 ((RectangleY1 5) 13)
 ((RectangleY2 5) 6)
 ((RectangleX1 6) 10)
 ((RectangleX2 6) 10)
 ((RectangleY1 6) 0)
 ((RectangleY2 6) 6)
 ((RectangleX1 7) 24)
 ((RectangleX2 7) 6)
 ((RectangleY1 7) 19)
 ((RectangleY2 7) 11)
 ((RectangleX1 8) 15)
 ((RectangleX2 8) 7)
 ((RectangleY1 8) 11)
 ((RectangleY2 8) 12)
 ((RectangleX1 9) 0)
 ((RectangleX2 9) 8)
 ((RectangleY1 9) 0)
 ((RectangleY2 9) 9)
 ((RectangleX1 10) 20)
 ((RectangleX2 10) 10)
 ((RectangleY1 10) 0)
 ((RectangleY2 10) 11)
 ((RectangleX1 11) 5)
 ((RectangleX2 11) 10)
 ((RectangleY1 11) 10)
 ((RectangleY2 11) 20))
"""

def parse_input(input_str):
    lines = input_str.strip().replace('(', '').replace(')', '').split('\n')
    rect_dict = {}
    
    for line in lines:
        parts = line.strip().split()
        key = f"{parts[0]} {parts[1]}"
        value = int(parts[2])
        rect_dict[key] = value
    
    rectangles = []
    rect_count = max(int(key.split()[1]) for key in rect_dict.keys())
    
    for i in range(1, rect_count + 1):
        x1 = rect_dict[f"RectangleX1 {i}"]
        y1 = rect_dict[f"RectangleY1 {i}"]
        x2 = rect_dict[f"RectangleX2 {i}"]
        y2 = rect_dict[f"RectangleY2 {i}"]
        rectangles.append((x1, y1, x2, y2))
    
    return rectangles

def convert_to_sysrect(rectangles):
    output = "std::vector<SysRect> rectangles = {\n"
    for i, (x1, y1, x2, y2) in enumerate(rectangles, 1):
        output += f"    rectFactory.CreateRect({x1}, {y1}, {x2}, {y2})"
        if i < len(rectangles):
            output += ",\n"
    output += "\n};"
    return output

rectangles = parse_input(input_data)
output = convert_to_sysrect(rectangles)

print(output)
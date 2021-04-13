import sqlite3


def create_connection(db_file):
    conn = None

    try:
        conn = sqlite3.connect(db_file)
    except sqlite3.Error as e:
        print(e)

    return conn


def select_tasks(conn, f_c, s_c, s_f):
    cur = conn.cursor()
    cur.execute(f"SELECT condition FROM Talks WHERE {f_c} and {s_c} ORDER BY {s_f}")

    rows = cur.fetchall()

    for row in rows:
        print(row[0])


file_name = 'E_input.txt'

with open(file_name) as f:
    db_name = f.readline().strip()
    f_c = f.readline().strip()
    s_c = f.readline().strip()
    s_f = f.readline().strip()

conn = create_connection(db_name)
with conn:
    select_tasks(conn, f_c, s_c, s_f)

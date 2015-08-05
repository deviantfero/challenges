import urllib.request
import re

img = ".jpg" #global variable

# this function fetchs the html and scans for likely image files #
##################################################################

def get_img_header():
    urllib.request.urlretrieve( "http://deviantart.com", "page.txt" )
    f = open( "page.txt", "r" )
    this = []
    for line in f:
        string = f.readline()
        if( img in string ):
            this.append( string )
    return this

def filter_img( li ):
    cl_stage1 = []
    cleansed = []
    for x in range( 0, len( li ) ):
       cl_stage1.append( re.split( r'[\"\'?()]', li[x] ) )
       #making use of regular expressions i filter out trash from the
       #code, and append it to the clean stage 1 list
    for x in range( 0, len( cl_stage1 ) ):
        for y in range( 0, len( cl_stage1[x] ) ):
            if( img in cl_stage1[x][y] and "http" in cl_stage1[x][y] ):
                cleansed.append( cl_stage1[x][y] )
    return cleansed

def download_img( clean_links ):
    filename = []
    for x in range( 0, len( clean_links ) ):
        filename.append( "img" + str(x) + ".jpg" )
        print( "Downloading -- %s"%clean_links[x] )
        urllib.request.urlretrieve( clean_links[x], filename[x] )

dirty_links = get_img_header()
clean_links = filter_img( dirty_links )
download_img( clean_links )

#print( images )

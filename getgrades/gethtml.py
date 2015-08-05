#!/usr/bin/python3
import urllib.request
import re
from sys import argv

usage = "-h for this message\n-f to pick a format (jpg by default)\nUsage:\n" + argv[0] + " \"link\" "

##################################################################
# this function fetchs the html and scans for likely image files 
##################################################################

def get_img_header( url ):
    urllib.request.urlretrieve( url, "page.txt" )
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
        filename.append( "img" + str(x) + img )
        print( "Downloading -- %s"%clean_links[x] )
        urllib.request.urlretrieve( clean_links[x], filename[x] )

###############################
#           MAIN              
###############################

img = ".jpg"
url = argv[1]
if( url == "-f" ):
    if( argv[2] != "jpg" and argv[2] != "png" and argv[2] != "gif" ):
        print( "this is an invalild format" )
        exit()
    elif( not( "http" in argv[3] ) ):
        print( "this is not a valid url" )
        exit()
    else:
        img = "." + argv[2]
        url = argv[3]
elif( url == "-h" ):
    print( usage )
    exit()
dirty_links = get_img_header( url )
clean_links = filter_img( dirty_links )
download_img( clean_links )


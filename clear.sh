#!/bin/csh
rm *.csh
rm *.err
rm *.out
rm *.dataset
rm *.report
rm *.session.xml
rm *.eps
rm *.condor
rm *.log
rm -r *.package*
rm -r LocalLibraries.zip
rm output/csh/*
rm output/list/*
rm output/report/*
rm output/stderr/*
rm output/stdout/*
rm output/output/*.root
rm output/tree/*.root
rm output/script/*
echo "All done."

use strict;

use vars qw(%dir_list);
BEGIN { %dir_list = (
	"art_Persistncy_Common" => "art_Persistncy_Common canvas_Persistency_Common",
	"art_Persistency_Provenance" => "art_Persistency_Provenance canvas_Persistency_Provenance",
	"art_Persistency_Common_dict" => "canvas_Persistency_Common_dict",
	"art_Persistency_StdDictionaries" => "canvas_Persistency_StdDictionaries",
	"art_Persistency_StdDictionaries_dict" => "canvas_Persistency_StdDictionaries_dict",
	"art_Persistency_WrappedStdDictionaries" => "canvas_Persistency_WrappedStdDictionaries",
	"art_Persistency_WrappedStdDictionaries_dict" => "canvas_Persistency_WrappedStdDictionaries_dict",
	"art_Utilities" => "art_Utilities canvas_Utilities"
		       ); }

foreach my $lib (sort keys %dir_list) {
   next if m&add_subdirectory&i;
   next if m&simple_plugin&i;
  #s&\b\Q${lib}\E([^\.\s]*\b)([^\.]|$)&$dir_list{$lib}${1}${2}&g and last;
  s&\b\Q${lib}\E\b([^\.]|$)&$dir_list{$lib}${1}${2}&g and last;
}

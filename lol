set val = 0
foreach scen ( a b )
echo -n $scen
if ($scen == a)
then
echo -n
$scen
else
echo -n $val
endif
end
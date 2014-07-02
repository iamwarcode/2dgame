if [ -z $GDIR ]
  then
    PS1="$PS1 (game-on) "
    export PS1
    export GDIR=`pwd`
  else
    echo "already activated"
fi
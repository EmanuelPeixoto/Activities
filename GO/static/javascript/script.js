function deleteuser(id){
  fetch('172.20.53.181:8080/dashboard/'+id, {
    method:'DELETE'
	})
}

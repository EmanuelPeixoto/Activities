document.getElementById('deleteButton').addEventListener('click', function() {
      const resourceId = this.getAttribute('user-id');
      const url = `172.20.53.181/dashboard/${resourceId}`;

      fetch(url, {
        method: 'DELETE',
        headers: {
          'Content-Type': 'application/json',
          // You may need to include additional headers, such as authentication tokens
        },
        // You can include a request body if needed
        // body: JSON.stringify({ /* data to be sent */ }),
      })
        .then(response => {
          if (!response.ok) {
            throw new Error('Network response was not ok');
          }
          return response.text(); // or response.text() if the response is not JSON
        })
        .then(data => {
          // Handle the response data
          console.log('Success:', data);
          // You can add additional code here to update the UI or perform other actions
        })
        .catch(error => {
          console.error('Error:', error);
        });
    });

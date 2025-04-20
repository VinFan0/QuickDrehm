# Load Windows Forms and Drawing namespaces
Add-Type -AssemblyName System.Windows.Forms
Add-Type -AssemblyName System.Drawing

# Read x,y coordinate pairs from input.txt
$x = @()
$y = @()
Get-Content "input.txt" | ForEach-Object {
    $parts = $_ -split ","
    if ($parts.Length -eq 2) {
        $xi = [float]$parts[0]
        $yi = [float]$parts[1]
        $x += $xi
        $y += $yi
    }
}

# Create the form
$form = New-Object System.Windows.Forms.Form
$form.Text = "Plot of X vs Y"
$form.Width = 600
$form.Height = 600

# Create a PictureBox for drawing
$pictureBox = New-Object System.Windows.Forms.PictureBox
$pictureBox.Dock = 'Fill'
$pictureBox.BackColor = 'White'
$form.Controls.Add($pictureBox)

# Handle the Paint event
$pictureBox.Add_Paint({
    param($sender, $e)

    $g = $e.Graphics
    $pen = New-Object System.Drawing.Pen([System.Drawing.Color]::Blue, 2)
    $brush = [System.Drawing.Brushes]::Blue

    $width = $pictureBox.Width
    $height = $pictureBox.Height

    # Normalize coordinates
    $xMin = ($x | Measure-Object -Minimum).Minimum
    $xMax = ($x | Measure-Object -Maximum).Maximum
    $yMin = ($y | Measure-Object -Minimum).Minimum
    $yMax = ($y | Measure-Object -Maximum).Maximum

    function Normalize($val, $min, $max, $size) {
        if ($max - $min -eq 0) { return $size / 2 } # avoid division by zero
        return (($val - $min) / ($max - $min)) * $size
    }

    # Draw each point
    for ($i = 0; $i -lt $x.Count; $i++) {
        $px = Normalize $x[$i] $xMin $xMax ($width - 10) + 5
        $py = $height - (Normalize $y[$i] $yMin $yMax ($height - 10) + 5) # flip Y
        $g.FillEllipse($brush, $px - 3, $py - 3, 6, 6)
    }
})

# Show the form
$form.ShowDialog()
